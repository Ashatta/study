#include <iostream>
#include <fstream>
#include <string>
#include <stack>

/**
 * The program obtains comments from files
 * which are given to it as command line arguments
 */

using namespace std;

inline bool isComment(stack<char> &st)
{
    return st.top() == 'c' || st.top() == 'l';
    // 'c' == "comment" /* */
    // 'l' == "line comment" //
}

inline bool isQuote(stack<char> &st)
{
    return st.top() == '\'' || st.top() == '"';
}

inline bool isSlash(stack<char> &st)
{
    return st.top() == '/' && st.top() == '\\';
}

void slash(stack<char> &st, string &comment, ofstream &out)
{
    if (st.empty())
    {
        st.push('/');
        return;
    }
    if (st.top() == '/')
    {
        st.pop();
        st.push('l');
        comment = "//";
    }
    else if (st.top() == '*')
        if (comment[comment.size() - 1] != '*')
            comment += '/';
        else
        {
            st.pop(); 
            st.pop(); 
            comment += '/'; 
            out << comment << endl;
        }
    else if (isComment(st))
        comment += '/';
}

void backSlash(stack<char> &st, string &comment)
{
    if (!st.empty())
        if (isQuote(st))
            st.push('\\');
        else if (isSlash(st))
            st.pop();
        else if (isComment(st) || st.top() == '*')
            comment += '\\';
}

void quote(stack<char> &st, string &comment, char ch)
{
    if (st.empty())
    {
        st.push(ch);
        return;
    }
    if (st.top() == '\\' || st.top() == ch)
        st.pop();
    else if (isComment(st) || st.top() == '*')
        comment += ch;
}

void endOfLine(stack<char> &st, string &comment, ofstream &out)
{
    if (!st.empty())
        if (st.top() != 'c' && st.top() != '*')
        {
            if (st.top() == 'l')
                out << comment << endl;
            while (!st.empty())
                st.pop();
        }
        else
            comment += '\n';
}

void otherSymbols(stack<char> &st, string &comment, char ch)
{
    if (!st.empty())
        if (isComment(st) || st.top() == '*')
            comment += ch;
        else if (isSlash(st))
            st.pop();
}

void asterisk(stack<char> &st, string &comment)
{
    if (!st.empty())
        if (st.top() == '/')
        {
            st.pop();
            st.push('c'); 
            comment = "/*";
        }
        else if (st.top() == '*' || isComment(st))
        {
            comment += '*';
            if (st.top() == 'c')
                st.push('*');
        }
}

void processFile(ifstream &in, ofstream &out)
{
    stack<char> st;
    string comment;
    char ch = in.get();
    while (!in.eof())
    {
        switch (ch)
        {
            case '\\' : 
                backSlash(st, comment);
                break;
            case '\'' : case '"' :
                quote(st, comment, ch); 
                break;
            case '/' : 
                slash(st, comment, out);            
                break;
            case '\n':
                endOfLine(st, comment, out);
                break;
            case '*' :
                asterisk(st, comment);
                break;
            default :
                otherSymbols(st, comment, ch);
        }
        ch = in.get();
    }
} 

int main(int argc, char * argv[])
{
    if (argc == 1)
    {
        cerr << "Try \"./hw5.task3 [filenames]\"" << endl;
        return 1;
    }

    ofstream out("output.ch");
    for (int i = 1; i < argc; ++i)
    {
        ifstream in(argv[i]);

        if (!in)
        {
            out << "Can't open the file \"" 
                << argv[i] << "\"\n" << endl;
            continue;
        }

        out << "Comments from the file \"" << argv[i] << "\"" << endl;
        processFile(in, out);
        out << endl;
                  
        in.close();
    }
    out.close();

    clog << "See the result in \"output.ch\"" << endl;
    return 0;
}

