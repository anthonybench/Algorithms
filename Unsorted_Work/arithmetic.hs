-- ==============================================
-- ==============================================
-- Arithmetic Evaluation Tool
--
-- Operations:
--    > Tokenizer & lexer
--    > Dijkstra's shunting-yard algorithm
--    > Parser
--    > Evaluator
--
-- Isaac Yep
-- ==============================================
-- ==============================================

-- **************************************
-- Pre-processors
-- **************************************
module Railroad where
import Data.Char as CharData

-- **************************************
-- Tokenizer & Lexer
-- **************************************
-- A token can be either an operator or a numeric literal
data Token = OpToken Char | NumToken Int | OpenParen | CloseParen
  deriving (Show, Eq)

-- Left or right associativity
data Associativity = L | R
  deriving (Show, Eq)

-- Turn a string into a list of tokens, without assuming that spaces separate the tokens
tokenize :: String -> [Token]
tokenize str = result where
    (result, _) = performLex ([], str)

performLex :: ([Token], String) -> ([Token], String)
performLex (ts, "") = (ts, "")
performLex (ts, str) = performLex(ts ++ ts', str')
    where (ts', str') = lex1(str)

lex1 :: String -> ([Token], String)
-- lexically analyze a token from the argument string, returning a list of tokens found,
-- and the remainder of the string.  If the String starts with spaces, they will be
-- consumed, but no tokens emitted.
lex1 "" = ([], "")
lex1 str@(c:cs)
     | CharData.isSymbol c || c `elem` "-*&/" = ([OpToken c], cs)
     -- isSymbol is true for Math, Currrency, Modifier (incl ^) and "Other" Symbols
     | CharData.isSymbol c || c `elem` "(" = ([OpenParen], cs)
     | CharData.isSymbol c || c `elem` ")" = ([CloseParen], cs)
     | CharData.isSeparator c = ([], cs)
     | CharData.isDigit c = ([ numTokenFrom str ], removeDigits str)
          where numTokenFrom str = NumToken (read (takeWhile CharData.isDigit str))
                removeDigits str = dropWhile CharData.isDigit str


-- **************************************
-- Dijkstra's shunting-yard algorithm
-- **************************************
-- operator precedence
precedence :: Token -> Int
precedence (OpToken '+') = 1
precedence (OpToken '-') = 1
precedence (OpToken '*') = 2
precedence (OpToken '/') = 2
precedence (OpToken '^') = 3
precedence (NumToken x) = error ("Asking for precedence of NumToken " ++ show x)

-- operator associativity
assoc :: Token -> Associativity
assoc (OpToken '+') = L
assoc (OpToken '-') = L
assoc (OpToken '*') = L
assoc (OpToken '/') = L
assoc (OpToken '^') = R
assoc (NumToken x) =  error ("Asking for associativity of NumToken " ++ show x)

-- operator resolving
opFun :: Char -> (Int -> Int -> Int)
opFun '+' = (+)
opFun '-' = (-)
opFun '*' = (*)
opFun '/' = div
opFun '^' = (^)
opFun x = error ("Can't determine function for operator " ++ [x])

-- Convert infix to RPN using shunting yard algorithm
data Yard = Yard            -- a shunting Yard has three components
                 [Token]   -- input
                 [Token]   -- output, most recent output at tail
                 [Token]   -- opStack, head is top

shunt :: [Token] -> [Token]
shunt toks = output where
    Yard _ output _ = performShunt (Yard toks [] [])

performShunt :: Yard -> Yard
-- Base case: if there's no more input to consume, output all the operators
-- in the opStack, and return
performShunt (Yard [] output' opStack') = Yard [] (output' ++ opStack') []
-- Otherwise, apply shunt1 to do one step of the shunting, and recurse
performShunt y = performShunt (shunt1 y)

shunt1 :: Yard -> Yard
-- Performs a single step in Dijkstra's shunting yard algorithm, on non-empty input
-- Transforms an old shunting yard (indicated by variables with ') to a new one
shunt1 (Yard (NumToken n : ts) output' opStack') =
      -- There is a number at the head of our input token list
      Yard ts (output' ++ [NumToken n]) opStack'
      
shunt1 (Yard (t : ts) output' []) =
      -- There is an operator token at the head of our input list, and
      -- the operator stack is empty: push the operator to the op stack
      Yard ts output' [t]

-- Dealing with parentheses
-- open paren
shunt1 (Yard (OpenParen : ts) output' opStack') =
      Yard ts output' (OpenParen:opStack')
-- close paren, open paren is on the top of the opStack
shunt1 (Yard (CloseParen : ts) output' opStack'@(OpenParen : os)) =
      Yard ts output' os
-- close parent, operator is on the top of the opStack
shunt1 (Yard input'@(CloseParen : ts) output' opStack'@(o : os)) =
      Yard input' (output' ++ [o]) os
-- operator, open paren is on the top of the opStack
shunt1 (Yard input'@(t : ts) output' opStack'@(OpenParen : os)) =
      Yard ts output' (t : opStack')

-- standard case
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
  evalWithStack (OpToken op:xs) stack =
    -- Pop the top two numbers off the stack, apply operation
      let (n1:stack') = stack   -- n1 will be right operand
          (n2:stack'') = stack' -- n2 will be left operand
          newStack = (opFun op n2 n1) : stack''
      in evalWithStack xs newStack


-- **************************************
-- Parse, then calculate
-- **************************************
-- Get list of tokens corresponding to our input string
parse :: String -> [Token]
parse = shunt . tokenize

-- Use shunting algorithm to evaluate any valid arithmatic expression
evalExp :: String -> Int
evalExp = evalRPN . parse