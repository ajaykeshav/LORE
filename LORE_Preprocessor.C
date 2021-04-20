// ROSE is a tool for building preprocessors, this file is an example preprocessor built with ROSE.
// rose.C: Example (default) ROSE Preprocessor: used as a preprocessor stage to make the LORE Codelets
// conducive for testing MathWorks CGIR optimizations

#include "rose.h"
#include <iostream>
#include <string>
#include <random>
#include <ctime>

#define IS_SIMPLE_VAR true
#define IS_NOT_SIMPLE_VAR false

// Build an accumulator attribute, fancy name for what is essentially a global variable :-).
class AccumulatorAttribute
{
public:
    int forLoopCounter;
    Rose_STL_Container<SgInitializedName*> globalVariables;

    // Specific constructors are optional
    AccumulatorAttribute () { forLoopCounter = 0;}
    AccumulatorAttribute ( const AccumulatorAttribute & X ) {}
    AccumulatorAttribute & operator= ( const AccumulatorAttribute & X ) { return *this; }

    /* Member function to gather all globals and convert pointer types to arrays */
    void buildListOfGlobalVariables(SgSourceFile *);

    /* Member function to flatten pointer types to array types from a list of variable declarations */
    void flattenPointerTypesToArrays(SgVariableDeclaration*, bool);

    /* Member function to determine the smallest array variable in the source AST */
    int determineLeastSizeAmongArrayVars(SgNode*);
};

class visitorTraversal : public AstSimpleProcessing
{
public:
    static AccumulatorAttribute accumulatorAttribute;
    virtual void visit(SgNode* n);
};

class nestedVisitorTraversal : public AstSimpleProcessing
{
public:
    static AccumulatorAttribute nestedAccumulatorAttribute;
    virtual void visit(SgNode *n);
};

void AccumulatorAttribute::flattenPointerTypesToArrays(SgVariableDeclaration *variableDeclaration, bool isSimpleVar)
{
    Rose_STL_Container<SgInitializedName*> &variableList = variableDeclaration->get_variables();
    Rose_STL_Container<SgInitializedName*>::iterator var = variableList.begin();
    while(var != variableList.end()){
        SgType *complete_type = (*var)->get_type();
        ROSE_ASSERT(complete_type != NULL);

        /* remove restrict storage class modifier if any (not supported by EDG parser) */
        SgType *type = complete_type->stripTypedefsAndModifiers();

        SgPointerType *ptr_type = isSgPointerType(type);
        if(ptr_type) {
            SgType *base_type = ptr_type->get_base_type();
            SgArrayType *array_type = new SgArrayType(base_type);

            /* array size is arbitrary */
            unsigned randSize = (rand() % 301) + 80;
            SgExpression *array_size = SageBuilder::buildIntVal(randSize);
            array_type->set_number_of_elements(randSize);
            array_type->set_index(array_size);
            array_type->set_is_variable_length_array(false);

            /* handle double pointers */
            SgPointerType *double_ptr_type = isSgPointerType(base_type);
            if(double_ptr_type){
                array_type->set_base_type(double_ptr_type->get_base_type());
                SgArrayType *array_type_double_pointer = new SgArrayType(array_type);

                /* fix the max size of any array to a constant */
                unsigned arraySize_dp = (rand() % 301) + 80;
                SgExpression *array_size_double_pointer = SageBuilder::buildIntVal(arraySize_dp);
                array_type_double_pointer->set_number_of_elements(arraySize_dp);
                array_type_double_pointer->set_index(array_size_double_pointer);
                array_type_double_pointer->set_is_variable_length_array(false);
                type = array_type_double_pointer;
            }
            else {
                type = array_type;
            }
            (*var)->set_type(type);
        }
        if(isSimpleVar) {
            visitorTraversal::accumulatorAttribute.globalVariables.push_back(*var);
        }
        var++;
    }
}

void AccumulatorAttribute::buildListOfGlobalVariables(SgSourceFile *file)
{
    ROSE_ASSERT(file != NULL);
    SgGlobal *globalScope = file->get_globalScope();
    ROSE_ASSERT(globalScope != NULL);
    SgDeclarationStatementPtrList declStmt = globalScope->get_declarations();
    Rose_STL_Container<SgDeclarationStatement*>::iterator i = declStmt.begin();
    while(i != declStmt.end()) {
        SgVariableDeclaration *variableDeclaration = isSgVariableDeclaration(*i);
        if(variableDeclaration != NULL){
            flattenPointerTypesToArrays(variableDeclaration, IS_SIMPLE_VAR);

            /* This declaration is no longer needed, will be later moved to local scope */
            SageInterface::removeStatement(*i);
        }
        else {
            SgTypedefDeclaration *typedefDeclaration = isSgTypedefDeclaration(*i);

            /* Handle typedefs defining structs containing pointer members */
            if(typedefDeclaration != NULL) {
                SgDeclarationStatement *definingDecl = typedefDeclaration->get_baseTypeDefiningDeclaration();
                if(definingDecl != NULL) {
                    SgDeclarationStatement *structDefn = definingDecl->get_definingDeclaration();
                    SgClassDeclaration *classDecl = isSgClassDeclaration(structDefn);
                    if (classDecl != NULL) {
                        SgClassDefinition *classDefn = classDecl->get_definition();
                        ROSE_ASSERT(classDefn != NULL);
                        SgDeclarationStatementPtrList &memberList = classDefn->get_members();
                        for(SgDeclarationStatementPtrList::iterator mem = memberList.begin(); mem != memberList.end(); ++mem) {
                            SgVariableDeclaration *memberVarDecl = isSgVariableDeclaration(*mem);
                            if(memberVarDecl != NULL) {
                                flattenPointerTypesToArrays(memberVarDecl,IS_NOT_SIMPLE_VAR);
                            }
                        }
                    }
                }
            }
        }
        i++;
    }
}

int AccumulatorAttribute::determineLeastSizeAmongArrayVars(SgNode* n)
{
    int least_size = 380;

    /* Gather all pointer or array reference expressions in scope */
    Rose_STL_Container<SgNode*> arrayAccess = NodeQuery::querySubTree(n,V_SgPntrArrRefExp);

    for(Rose_STL_Container<SgNode*>::iterator it = arrayAccess.begin(); it != arrayAccess.end(); ++it){
        SgBinaryOp *fullExp = isSgBinaryOp(*it);
        ROSE_ASSERT(fullExp != NULL);

        /* Get the compound type of the referenced node */
        SgExpression *arrVarExp = fullExp->get_lhs_operand();
        SgType *arrayVarType = arrVarExp->get_type();
        SgArrayType *arrayVar = isSgArrayType(arrayVarType);
        if(arrayVar != NULL){
            int sz = arrayVar->get_number_of_elements();
            if(sz < least_size)
                least_size = sz;
        }
    }
    return least_size;
}

// declaration required for static data members
AccumulatorAttribute visitorTraversal::accumulatorAttribute;
AccumulatorAttribute nestedVisitorTraversal::nestedAccumulatorAttribute;

void visitorTraversal::visit(SgNode* n)
{
    if(isSgFunctionDefinition(n) != NULL)
    {
        /* Assuming there's only one function in file , name it main and set integer return type */
        SgFunctionDefinition *func = isSgFunctionDefinition(n);
        SgFunctionDeclaration *func_declaration = func->get_declaration();
        ROSE_ASSERT(func_declaration != NULL);
        func_declaration->set_name(SgName("main"));
        SgFunctionType *func_type = func_declaration->get_type();
        SgType *integerTy = new SgTypeInt();
        ROSE_ASSERT(integerTy != NULL);
        func_type->set_orig_return_type(integerTy);
        func_declaration->set_type(func_type);
        func->set_declaration(func_declaration);

        SgBasicBlock *func_body = func->get_body();
        ROSE_ASSERT(func_body != NULL);

        Sg_File_Info *sourceLocation = Sg_File_Info::generateDefaultFileInfoForTransformationNode();
        ROSE_ASSERT(sourceLocation != NULL);

        /* insert needed declarations here to bring all globals to local scope */
        for(Rose_STL_Container<SgInitializedName*>::iterator var = accumulatorAttribute.globalVariables.begin(); var != accumulatorAttribute.globalVariables.end(); ++var){
            SgType *type = (*var)->get_type();
            ROSE_ASSERT(type != NULL);
            SgName name = (*var)->get_name();
            SgVariableDeclaration *variableDeclaration = SageBuilder::buildVariableDeclaration(name, type);
            SageInterface::prependStatement(variableDeclaration,func_body);
        }

        /* insert return 0 at the end */
        SgExpression *retVal = SageBuilder::buildIntVal(0);
        SgReturnStmt *retStmt = SageBuilder::buildReturnStmt(retVal);
        SgStatement *lastStmt = SageInterface::getLastStatement(func_body);
        SageInterface::insertStatementAfter(lastStmt,retStmt);
    }
}

void nestedVisitorTraversal::visit(SgNode* n)
{
    if (isSgForStatement(n) != NULL)
    {
        /* Extract for loops and fold the upper bounds to constants if it is not already a constant */
        /* TODO: Handle variable lower bounds */
        SgForStatement *forStmt = isSgForStatement(n);
        SgExpression *loopCondExpr = forStmt->get_test_expr();
        ROSE_ASSERT(loopCondExpr != NULL);
        SgBinaryOp *op = isSgBinaryOp(loopCondExpr);
        ROSE_ASSERT(op != NULL);
        SgExpression *boundVal = op->get_rhs_operand();
        SgIntVal *varType = isSgIntVal(boundVal);
        if(varType == nullptr){
            /* set the upper bound to a value less than or equal to the least value based on array sizes */
            int maxBound = nestedVisitorTraversal::nestedAccumulatorAttribute.determineLeastSizeAmongArrayVars(n);
            int upperBound = rand() % maxBound + 1;
            SgExpression *upperBoundExp = SageBuilder::buildIntVal(upperBound);
            op->set_rhs_operand(upperBoundExp);
        }
        visitorTraversal::accumulatorAttribute.forLoopCounter++;
    }
}

int
main ( int argc, char* argv[] )
{
    // Initialize and check compatibility. See Rose::initialize
    ROSE_INITIALIZE;

    SgProject* project = frontend(argc,argv);
    ROSE_ASSERT (project != NULL);

    // Build the traversal object which brings all globals to local scope and adjusts main function's prototype
    visitorTraversal exampleTraversal;
    nestedVisitorTraversal constantLoopBounds;

    // Build list of global variables
    const SgFilePtrList &fileList = project->get_fileList();
    SgFilePtrList::const_iterator file = fileList.begin();
    SgSourceFile *f = isSgSourceFile(*file);
    visitorTraversal::accumulatorAttribute.buildListOfGlobalVariables(f);
    SgGlobal *globalScope = f->get_globalScope();
    ROSE_ASSERT(globalScope != NULL);
    srand(time(0));
    // Call the traversal starting at the project node of the AST
    // can be specified to be preorder or postorder).
    exampleTraversal.traverseInputFiles(project,preorder);

    // now convert all variable loop bounds to constants based on the array accesses within the scope
    constantLoopBounds.traverseInputFiles(project,postorder);

    // Ensure the AST is sane after all transformations are complete
    AstTests::runAllTests(project);

    // Need this since we want to delegate the build procedure of the transformed source to the backend compiler
    return backend(project);
}