//  ICE Revision: $Id: FieldValueExpressionDriverYY.H,v 44d497836cd6 2012-07-02 17:38:40Z bgschaid $ 

#ifndef VALUE_EXPRESSION_DRIVER_YY_H
#define VALUE_EXPRESSION_DRIVER_YY_H

#include "FieldValueExpressionDriver.H"

#define YY_DECL int parserFieldlex(parserField::FieldValueExpressionParser::semantic_type* yylval_param,parserField::location* yylloc,void *yyscanner,Foam::FieldValueExpressionDriver &driver,int& start_token,int& numberOfFunctionChars)

YY_DECL;

#endif
