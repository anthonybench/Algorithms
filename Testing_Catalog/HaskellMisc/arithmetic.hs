-- ==============================================
-- ==============================================
-- Arithmetic Evaluation Tool
--
-- Operations:
--    > Tokenizer & lexer
--    > Dijkstra's shunting-yard algorithm
--    > Parser
--    > Evaluator
--    > Abstract Syntax Tree Interpretation
--
-- Isaac Yep
-- ==============================================
-- ==============================================


-- **************************************
-- Pre-processors
-- **************************************
module ArithParse where
import Data.Char as CharData

-- **************************************
-- Tokenizer & Lexer
-- **************************************
-- A token can be either an operator or a numeric literal
data Token = OpToken Char  | NumToken Int | OpenParen | CloseParen | Neg | Sq
  deriving (Show, Eq)

-- Left or right associativity
data Associativity = L | R
  deriving (Show, Eq)

-- Turn a string into a list of tokens, without assuming that spaces separate the tokens
tokenize :: String -> [Token]
tokenize str = result where
    (result, _) = performLex ([], str)

performLex :: ([Token], String) -> ([Token], String)
-- lexically-analyze the string provided as the second argument.
-- The first argument accumulates the result; we append new tokens to the end

performLex (ts, "") = (ts, "")
-- Base case: if the string is empty, there is nothing to do
performLex ([], '-':cs) = performLex(ts', str')
    where (ts', str') = lex1("neg" ++ cs)
performLex (ts, str@('-':cs))
    | (last(ts) == (OpToken '+')) = performLex(ts ++ ts', str') 
    | (last(ts) == (OpToken '-')) = performLex(ts ++ ts', str')
    | (last(ts) == (OpToken '*')) = performLex(ts ++ ts', str')
    | (last(ts) == (OpToken '/')) = performLex(ts ++ ts', str')
    | (last(ts) == (OpToken '^')) = performLex(ts ++ ts', str')
    | (last(ts) == Neg) = performLex(ts ++ ts', str')
    | (last(ts) == Sq) = performLex(ts ++ ts', str')
    where
      (ts', str') = lex1("neg" ++ cs)
performLex (ts, str) = performLex(ts ++ ts', str')
    where (ts', str') = lex1(str)
-- if the string is non-empty, we call lex1 to perform one step of the lexing.


lex1 :: String -> ([Token], String)
-- lexically-analyze a token from the argument string, returning a pair containing
-- the list of tokens found, and the remainder of the string.  If the argument
-- String starts with spaces, they will be consumed, but no tokens emitted.

lex1 "" = ([], "")
lex1 str@(c:cs)
     | c == '(' = ([OpenParen], cs)
     | c == ')' = ([CloseParen], cs)
     | ((take 3 str) == "neg") = ([Neg], (drop 3 str))
     | ((take 2 str) == "sq") = ([Sq], (drop 2 str))
     | CharData.isSymbol c || c `elem` "-*&/" = ([OpToken c], cs)
     -- isSymbol is true for Math, Currency, Modifier (incl ^) and "Other" Symbols
     | CharData.isSeparator c = ([], cs)
     | CharData.isDigit c = ([ numTokenFrom str ], removeDigits str)
        where   numTokenFrom str = NumToken (read (takeWhile CharData.isDigit str))
                removeDigits str = dropWhile CharData.isDigit str


-- **************************************
-- Dijkstra's shunting-yard algorithm
-- **************************************
precedence :: Token -> Int
-- Determines precedence of an operator; larger numbers mean higher precedence
precedence (OpToken '+') = 1
precedence (OpToken '-') = 1
precedence (OpToken '*') = 2
precedence (OpToken '/') = 2
precedence (OpToken '^') = 3
precedence (Neg) = 4
precedence (Sq) = 4
precedence x = error ("Asking for precedence of " ++ show x)


assoc :: Token -> Associativity
-- returns the associativity of an operator
assoc (OpToken '+') = L
assoc (OpToken '-') = L
assoc (OpToken '*') = L
assoc (OpToken '/') = L
assoc (OpToken '^') = R
assoc (Neg) = R
assoc (Sq) = R
assoc (NumToken x) =  error ("Asking for associativity of NumToken " ++ show x)


opFun :: Token -> (Int -> Int -> Int)
-- returns the function corresponding to an operator character

opFun (OpToken '-') = (-)
opFun (OpToken '+') = (+)
opFun (OpToken '*') = (*)
opFun (OpToken '/') = div
opFun (OpToken '^') = (^)
opFun x = error ("Can't determine function for " ++ show x)


-- Convert infix to RPN using Dijkstra's shunting-yard algorithm

data Yard = Yard            -- a shunting Yard has three components
                 [Token]   -- input
                 [Token]   -- output, most recent output at tail
                 [Token]   -- opStack, head is top

shunt :: [Token] -> [Token]
shunt toks = output where
    Yard _ output _ = performShunt (Yard toks [] [])

performShunt :: Yard -> Yard
-- implements Dijkstra's shunting yard algorithm, transforming an input Yard
-- into an Output Yard.

performShunt (Yard [] output' opStack') = Yard [] (output' ++ opStack') []
-- Base case: if there's no more input to consume, output all the operators
-- in the opStack, and return

performShunt y = performShunt (shunt1 y)
-- Otherwise, apply shunt1 to do one step of the shunting, and recurse

shunt1 :: Yard -> Yard
-- Performs a _single step_ in Dijkstra's shunting yard algorithm, on non-empty input
-- Transforms an old shunting yard (indicated by variables with ') to a new one

shunt1 (Yard (NumToken n : ts) output' opStack') =
      -- There is a number at the head of our input token list
      Yard ts (output' ++ [NumToken n]) opStack'
shunt1 (Yard (OpenParen : ts) output' opStack') =
       Yard ts output' (OpenParen : opStack')
shunt1 (Yard (CloseParen : ts) output' (OpenParen : opStack')) =
       Yard ts output' opStack'
shunt1 (Yard (CloseParen : ts) output' (o : opStack')) =
       Yard (CloseParen : ts) (output' ++ [o]) opStack'
shunt1 (Yard (CloseParen : ts) output' []) = error "mismatched parenthesis"
shunt1 (Yard (t : ts) output' []) = 
      -- There is an operator token at the head of our input list, and
      -- the operator stack is empty: push the operator to the op stack
      Yard ts output' [t]
shunt1 (Yard input'@(t : ts) output' opStack'@(OpenParen : os)) =
      Yard ts output' (t : opStack')

-- ===================================================================
-- ===================================================================
shunt1 (Yard (Neg:ts) output' opStack') =
      Yard ts output' (Neg:opStack')
shunt1 (Yard (Sq:ts) output' opStack') =
      Yard ts output' (Sq:opStack')
shunt1 (Yard input' output' (Neg:ts)) =
      Yard input' (output' ++ [Neg]) ts
shunt1 (Yard input' output' (Sq:ts)) =
      Yard input' (output' ++ [Sq]) ts
-- ===================================================================
-- ===================================================================

shunt1 (Yard input'@(t : ts) output' opStack'@(o : os))
      -- If the top operator in the op stack o has higher precedence
      -- than the input operator t, or the top operator o has the same precedence
      -- as the input operator t and the current operator is left associative,
      -- push the top operator to the output and remove from the opStack
      | (precedence o > precedence t) || (precedence o == precedence t && assoc t == L) =
            Yard input' (output' ++ [o]) os
      -- Otherwise, push operator to the op stack
      | otherwise =
            Yard ts output' (t : opStack')


-- **************************************
-- Evaluate shunting-yard results (reverse polish notation)
-- **************************************
evalRPN :: [Token] -> Int
evalRPN [] = 0 -- Base case: empty list of tokens
evalRPN input = evalWithStack input [] where
  evalWithStack [] stack = head stack
  evalWithStack (NumToken n:xs) stack =
    -- We have a numeric token; push it to the stack
      evalWithStack xs (n : stack)
  evalWithStack (OpToken op:xs) (n1:n2:stack) =
    -- Pop the top two numbers off the stack, apply operation
      evalWithStack xs newStack
        where newStack = opFun (OpToken op) n2 n1 : stack

evalExp :: String -> Int
-- Use shunting algorithm to evaluate any valid arithmatic expression

evalExp = evalRPN . parse


parse :: String -> [Token]
-- Get list of tokens corresponding to our input string
parse = shunt . tokenize

-- **************************************
-- Abstract Syntax Tree (Parse Tree)
-- **************************************
-- A abstract syntax tree (AST) is a recursive data structure.
-- Each node is either a BinOpNode, which is comprised of
-- a token representing a binary function over integers and two AST children,
-- or else a NumberNode with a single integer value.
data AST = BinOpNode Token AST AST | NumberNode Int | UnOpNode Token AST

rpnToAst :: [Token] -> AST
-- This function converts a list of Reverse Polish Notation tokens into an AST

rpnToAst [] = NumberNode 0
-- this is the base case: the list of tokens is empty, so we return a tree with single leaf node

rpnToAst input = astWithStack input []
-- otherwise, we call the astWithStack function, passing the input and an empty stack


astWithStack :: [Token] -> [AST] -> AST
-- This is a helper-function used to implement rpnToAst.  Its first argument
-- is the input tokens list; its second argument is the stack
-- Each node on the stack can be thought of as a subtree of the final AST.
-- We keep a list of input tokens and a stack of ASTs, and assemble them into a single AST

astWithStack [] result = head result
-- If we have an empty input, we return whatever is left at the top of the stack.

astWithStack (NumToken n : xs) subtrees =
    astWithStack xs (NumberNode n : subtrees)
-- If a numeric token is encountered, we create a tree with just that value
-- and push it to the stack

astWithStack (Neg : os) (subtree1:subtrees) =
  astWithStack os newTree
  where newTree = (UnOpNode Neg (subtree1)) : subtrees
  
astWithStack (Sq : os) (subtree1:subtrees) =
  astWithStack os newTree
  where newTree = (UnOpNode Sq subtree1) : subtrees

astWithStack (OpToken o : os) (subtree1 : subtree2 : subtrees) = 
    astWithStack os newTree
    where newTree = (BinOpNode (OpToken o) subtree2 subtree1) : subtrees
-- If an operator token is encountered, we create a new tree with that
-- operator and the two trees from the top of the stack as its children.
-- This new tree is pushed to the stack.

-- **************************************
-- Evluate Parse Tree
-- **************************************
evalAST :: AST -> Int
evalAST (NumberNode n) = n
evalAST (BinOpNode tok left right)
  | (tok == (OpToken '+')) = (evalAST(left)) + (evalAST(right))
  | (tok == (OpToken '-')) = (evalAST(left)) - (evalAST(right))
  | (tok == (OpToken '*')) = (evalAST(left)) * (evalAST(right))
  | (tok == (OpToken '/')) = (evalAST(left)) `div` (evalAST(right))
  | (tok == (OpToken '^')) = (evalAST(left)) ^ (evalAST(right))
evalAST (UnOpNode tok down)
  | (tok == Neg) = negate(evalAST(down))
  | (tok == Sq) = evalAST(down) ^ 2

-- **************************************
-- User Function
-- **************************************
compute :: [Char] -> Int
compute s = evalAST(rpnToAst(parse(s)))


-- tests
s1 = "3 + 2 - (9 / 3)" -- 2
s2 = "sq 10" -- 100
s3 = "sq neg 2" -- 4
s4 = "neg sq 2" -- -4
s5 = "neg 3 * neg 2" -- 6
s6 = "-3"
s7 = "3+-4"
