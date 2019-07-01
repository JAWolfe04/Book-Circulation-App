//---------------------------------------------------------------------------------------
// Taken from String_Tokenizer.h provided by Mohammad Kuhail, kuhailm@umkc.edu
// Alterations we done to conform to the scope of the project 
//---------------------------------------------------------------------------------------
#pragma once

#include <string>

/** The string_tokenizer class splits a string into a sequence of subtrings,
called tokens, separated by delimeters.
*/
class StringTokenizer
{
public:
    /** Construct a String_Tokenizer
    @param source The string to be split into tokens
    @param delim The string containing the delimeters. If
    this parameter is omitted, a space character is assumed.
    */
    StringTokenizer(std::string source, std::string delim = " ") :
        source(source), delim(delim), start(0), end(0) {
        findNext();
    }

    /** Determine if there are more tokens
    @return true if there are more tokens
    */
    bool hasMoreTokens() {
        return start != std::string::npos;
    }

    /** Retrieve the next token
    @return the next token. If there are no more
    tokens, an empty string is returned
    */
    std::string nextToken() {
        // Make sure there is a next token
        if (!hasMoreTokens())
            return "";
        // Save the next token in return_value
        /*<snippet id="3" omit="false">*/
        std::string token = source.substr(start, end - start);
        /*</snippet>*/
        // Find the following token
        findNext();
        // Return the next token
        return token;
    }

private:
    /** Position start and end so that start is the index of the start
    of the next token and end is the end.
    */
    void findNext() {
        // Find the first character that is not a delimeter
        /*<snippet id="1" omit="false">*/
        start = source.find_first_not_of(delim, end);
        /*</snippet>*/
        // Find the next delimeter
        /*<snippet id="2" omit="false">*/
        end = source.find_first_of(delim, start);
        /*</snippet>*/
    }

    /** The string to be split into tokens */
    std::string source;
    /** The string of delimeters */
    std::string delim;
    /** The index of the start of the next token */
    size_t start;
    /** The index of the end of the next token*/
    size_t end;
};