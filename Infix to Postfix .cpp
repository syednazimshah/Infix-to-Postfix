// 2019342_Assignment 2                         //maaz tariq
//2019504 Assignment 2                         //syed nazim shah

#include <iostream>
#include <string>
using namespace std;

class stackInfix
{
    struct infixList     //input linked list
    {
        char elementInfix;
        infixList* next;
        infixList* prev;
    };
    infixList* headQ;

    struct postfixList  //output linked list
    {
        char elementPostfix;
        postfixList* next;
        postfixList* prev;
    };
    postfixList* headP;

    struct stackList   //operator stack
    {
        char elementOPstack;
        stackList* next;
        stackList* prev;
    };
    stackList* headS;

public:
    stackInfix()
    {
        headQ = NULL;
        headP = NULL; 
        headS = NULL;
    }
    void pushInfix(char pushit)//to pus the input string character by character into stack
    {
        infixList* ptrnew = new infixList;
        ptrnew->elementInfix = pushit;
        if (headQ == NULL)
        {
            headQ = ptrnew;
            ptrnew->next = ptrnew;
            ptrnew->prev = ptrnew;
        }
        else if(headQ->next==headQ)//if 1 node present
        {
            ptrnew->next = headQ;
            headQ->next = ptrnew;
            headQ->prev = ptrnew;
            ptrnew->prev = headQ;
            headQ = ptrnew;
        }
        else //if mutiple nodes present
        {
            infixList* ptrtemp = headQ;
            ptrtemp->prev = ptrnew;
            ptrnew->next = headQ;
            while (ptrtemp->next != headQ)
                ptrtemp = ptrtemp->next;
            ptrnew->prev = ptrtemp;
            ptrtemp->next = ptrnew;
            headQ = ptrnew;
        }
    }
    void InfixToPostfix(int len)
    {
        stackList* stkptr;
        postfixList* pstfxptr;
        infixList* infxptr;
        char compare, compare2;
        int i;
            stackList* ptrnewad = new stackList;//adding operator to stack
            for (int l = 0; l < len+2; l++) //repeat steps 3-6 until stack is empty
            {
                infxptr = headQ;
                compare = (infxptr->prev)->elementInfix;
                if (l != len+1) //delete from input list
                {
                    infixList* ptrdel = headQ->prev;//popping
                    headQ->prev = ptrdel->prev;
                    (ptrdel->prev)->next = headQ;
                    delete ptrdel;
                }
                if (compare == '/' || compare == '*' || compare == '+' || compare == '-' || compare == '^') //if operator
                {
                    if (compare == '/')
                    {
                        do {
                            if (headS != NULL)
                            {
                                i = 0;
                                compare2 = headS->elementOPstack;
                                if (compare2 == '/' || compare2 == '*' || compare2 == '^')
                                {
                                    postfixList* ptrnew = new postfixList;//adding
                                    ptrnew->elementPostfix = compare2;
                                    if (headP == NULL)
                                    {
                                        headP = ptrnew;
                                        ptrnew->next = ptrnew;
                                        ptrnew->prev = ptrnew;
                                    }
                                    else if (headP->next == headP)//if 1 node presemt
                                    {
                                        ptrnew->next = headP;
                                        headP->next = ptrnew;
                                        headP->prev = ptrnew;
                                        ptrnew->prev = headP;
                                        headP = ptrnew;
                                    }
                                    else //if mutiple nodes present
                                    {
                                        postfixList* ptrtemp = headP;
                                        ptrnew->next = headP;
                                        while (ptrtemp->next != headP)
                                            ptrtemp = ptrtemp->next;
                                        ptrnew->prev = ptrtemp;
                                        ptrtemp->next = ptrnew;
                                        headP = ptrnew;
                                    }

                                    stackList* ptrdel = headS;//popping
                                    (ptrdel->next)->prev = ptrdel->prev;
                                    (ptrdel->prev)->next = ptrdel->next;
                                    headS = ptrdel->next;
                                    delete ptrdel;
                                    i = 1;
                                }
                            }
                        } while (i == 1);
                        //stackList* ptrnew = new stackList;//adding operator to stack
                        ptrnewad->elementOPstack = '/';
                        if (headS == NULL)
                        {
                            headS = ptrnewad;
                            ptrnewad->next = ptrnewad;
                            ptrnewad->prev = ptrnewad;
                        }
                        else if (headS->next == headS)//if 1 node presemt
                        {
                            ptrnewad->next = headS;
                            headS->next = ptrnewad;
                            headS->prev = ptrnewad;
                            ptrnewad->prev = headS;
                            headS = ptrnewad;
                        }
                        else //if mutiple nodes present
                        {
                            stackList* ptrtemp = headS;
                            ptrnewad->next = headS;
                            while (ptrtemp->next != headS)
                                ptrtemp = ptrtemp->next;
                            ptrnewad->prev = ptrtemp;
                            ptrtemp->next = ptrnewad;
                            headS = ptrnewad;
                        }
                    }
                    if (compare == '*')
                    {
                        do {
                            if (headS != NULL)
                            {
                                i = 0;
                                compare2 = headS->elementOPstack;
                                if (compare2 == '/' || compare2 == '*' || compare2 == '^')
                                {
                                    postfixList* ptrnew2 = new postfixList;//adding
                                    ptrnew2->elementPostfix = compare2;
                                    if (headP == NULL)
                                    {
                                        headP = ptrnew2;
                                        ptrnew2->next = ptrnew2;
                                        ptrnew2->prev = ptrnew2;
                                    }
                                    else if (headP->next == headP)//if 1 node presemt
                                    {
                                        ptrnew2->next = headP;
                                        headP->next = ptrnew2;
                                        headP->prev = ptrnew2;
                                        ptrnew2->prev = headP;
                                        headP = ptrnew2;
                                    }
                                    else //if mutiple nodes present
                                    {
                                        postfixList* ptrtemp = headP;
                                        ptrnew2->next = headP;
                                        while (ptrtemp->next != headP)
                                            ptrtemp = ptrtemp->next;
                                        ptrnew2->prev = ptrtemp;
                                        ptrtemp->next = ptrnew2;
                                        headP = ptrnew2;
                                    }

                                    stackList* ptrdel = headS;//popping
                                    (ptrdel->next)->prev = ptrdel->prev;
                                    (ptrdel->prev)->next = ptrdel->next;
                                    headS = ptrdel->next;
                                    delete ptrdel;
                                    i = 1;
                                }
                            }
                        } while (i == 1);
                        //stackList* ptrnewadd = new stackList;//adding operator to stack
                        ptrnewad->elementOPstack = '*';
                        if (headS == NULL)
                        {
                            headS = ptrnewad;
                            ptrnewad->next = ptrnewad;
                            ptrnewad->prev = ptrnewad;
                        }
                        else if (headS->next == headS)//if 1 node presemt
                        {
                            ptrnewad->next = headS;
                            headS->next = ptrnewad;
                            headS->prev = ptrnewad;
                            ptrnewad->prev = headS;
                            headS = ptrnewad;
                        }
                        else //if mutiple nodes present
                        {
                            stackList* ptrtemp = headS;
                            ptrnewad->next = headS;
                            while (ptrtemp->next != headS)
                                ptrtemp = ptrtemp->next;
                            ptrnewad->prev = ptrtemp;
                            ptrtemp->next = ptrnewad;
                            headS = ptrnewad;
                        }
                    }
                    if (compare == '+')
                    {
                        i = 0;

                        do {
                            if (headS != NULL)
                            {
                                compare2 = headS->elementOPstack;
                                if (compare2 != ')' && compare2 != '(')
                                {
                                    postfixList* ptrnew = new postfixList;//adding
                                    ptrnew->elementPostfix = compare2;
                                    if (headP == NULL)
                                    {
                                        headP = ptrnew;
                                        ptrnew->next = ptrnew;
                                        ptrnew->prev = ptrnew;
                                    }
                                    else if (headP->next == headP)//if 1 node presemt
                                    {
                                        ptrnew->next = headP;
                                        headP->next = ptrnew;
                                        headP->prev = ptrnew;
                                        ptrnew->prev = headP;
                                        headP = ptrnew;
                                    }
                                    else //if mutiple nodes present
                                    {
                                        postfixList* ptrtemp = headP;
                                        ptrnew->next = headP;
                                        while (ptrtemp->next != headP)
                                            ptrtemp = ptrtemp->next;
                                        ptrnew->prev = ptrtemp;
                                        ptrtemp->next = ptrnew;
                                        headP = ptrnew;
                                    }

                                    stackList* ptrdel = headS;    //popping
                                    (ptrdel->next)->prev = ptrdel->prev;
                                    (ptrdel->prev)->next = ptrdel->next;
                                    headS = ptrdel->next;
                                    delete ptrdel;
                                    i = 1;
                                }
                            } 
                        } while (i == 1);

                        //stackList* ptrnewad;
                        ptrnewad->elementOPstack = '+';
                        if (headS == NULL)
                        {
                            headS = ptrnewad;
                            ptrnewad->next = ptrnewad;
                            ptrnewad->prev = ptrnewad;
                        }
                        else if (headS->next == headS)//if 1 node presemt
                        {
                            ptrnewad->next = headS;
                            headS->next = ptrnewad;
                            headS->prev = ptrnewad;
                            ptrnewad->prev = headS;
                            headS = ptrnewad;
                        }
                        else //if mutiple nodes present
                        {
                            stackList* ptrtemp = headS;
                            ptrnewad->next = headS;
                            while (ptrtemp->next != headS)
                                ptrtemp = ptrtemp->next;
                            ptrnewad->prev = ptrtemp;
                            ptrtemp->next = ptrnewad;
                            headS = ptrnewad;
                        }
                    }
                    if (compare == '-')
                    {
                        {
                            i = 0;

                            do {
                                if (headS != NULL)
                                {
                                    compare2 = headS->elementOPstack;
                                    if (compare2 != ')' && compare2 != '(')
                                    {
                                        postfixList* ptrnew = new postfixList;//adding
                                        ptrnew->elementPostfix = compare2;
                                        if (headP == NULL)
                                        {
                                            headP = ptrnew;
                                            ptrnew->next = ptrnew;
                                            ptrnew->prev = ptrnew;
                                        }
                                        else if (headP->next == headP)//if 1 node presemt
                                        {
                                            ptrnew->next = headP;
                                            headP->next = ptrnew;
                                            headP->prev = ptrnew;
                                            ptrnew->prev = headP;
                                            headP = ptrnew;
                                        }
                                        else //if mutiple nodes present
                                        {
                                            postfixList* ptrtemp = headP;
                                            ptrnew->next = headP;
                                            while (ptrtemp->next != headP)
                                                ptrtemp = ptrtemp->next;
                                            ptrnew->prev = ptrtemp;
                                            ptrtemp->next = ptrnew;
                                            headP = ptrnew;
                                        }

                                        stackList* ptrdel = headS;    //popping
                                        (ptrdel->next)->prev = ptrdel->prev;
                                        (ptrdel->prev)->next = ptrdel->next;
                                        headS = ptrdel->next;
                                        delete ptrdel;
                                        i = 1;
                                    }
                                }
                            } while (i == 1);

                            //stackList* ptrnewad;
                            ptrnewad->elementOPstack = '-';
                            if (headS == NULL)
                            {
                                headS = ptrnewad;
                                ptrnewad->next = ptrnewad;
                                ptrnewad->prev = ptrnewad;
                            }
                            else if (headS->next == headS)//if 1 node presemt
                            {
                                ptrnewad->next = headS;
                                headS->next = ptrnewad;
                                headS->prev = ptrnewad;
                                ptrnewad->prev = headS;
                                headS = ptrnewad;
                            }
                            else //if mutiple nodes present
                            {
                                stackList* ptrtemp = headS;
                                ptrnewad->next = headS;
                                while (ptrtemp->next != headS)
                                    ptrtemp = ptrtemp->next;
                                ptrnewad->prev = ptrtemp;
                                ptrtemp->next = ptrnewad;
                                headS = ptrnewad;
                            }
                        }
                    }
                    if (compare == '^')
                    {
                        i = 0;

                        do {
                            if (headS != NULL)
                            {
                                compare2 = headS->elementOPstack;
                                if (compare2 == '^')
                                {
                                    postfixList* ptrnew = new postfixList;//adding
                                    ptrnew->elementPostfix = compare2;
                                    if (headP == NULL)
                                    {
                                        headP = ptrnew;
                                        ptrnew->next = ptrnew;
                                        ptrnew->prev = ptrnew;
                                    }
                                    else if (headP->next == headP)//if 1 node presemt
                                    {
                                        ptrnew->next = headP;
                                        headP->next = ptrnew;
                                        headP->prev = ptrnew;
                                        ptrnew->prev = headP;
                                        headP = ptrnew;
                                    }
                                    else //if mutiple nodes present
                                    {
                                        postfixList* ptrtemp = headP;
                                        ptrnew->next = headP;
                                        while (ptrtemp->next != headP)
                                            ptrtemp = ptrtemp->next;
                                        ptrnew->prev = ptrtemp;
                                        ptrtemp->next = ptrnew;
                                        headP = ptrnew;
                                    }

                                    stackList* ptrdel = headS;    //popping
                                    (ptrdel->next)->prev = ptrdel->prev;
                                    (ptrdel->prev)->next = ptrdel->next;
                                    headS = ptrdel->next;
                                    delete ptrdel;
                                    i = 1;
                                }
                            }
                        } while (i == 1);
                        ptrnewad->elementOPstack = '^';
                        if (headS == NULL)
                        {
                            headS = ptrnewad;
                            ptrnewad->next = ptrnewad;
                            ptrnewad->prev = ptrnewad;
                        }
                        else if (headS->next == headS)//if 1 node presemt
                        {
                            ptrnewad->next = headS;
                            headS->next = ptrnewad;
                            headS->prev = ptrnewad;
                            ptrnewad->prev = headS;
                            headS = ptrnewad;
                        }
                        else //if mutiple nodes present
                        {
                            stackList* ptrtemp = headS;
                            ptrnewad->next = headS;
                            while (ptrtemp->next != headS)
                                ptrtemp = ptrtemp->next;
                            ptrnewad->prev = ptrtemp;
                            ptrtemp->next = ptrnewad;
                            headS = ptrnewad;
                        }
                    }
                }
                else if (compare == '(') //if left parentheses
                {
                    stackList* ptrnew = new stackList;
                    ptrnew->elementOPstack = compare;
                    if (headS == NULL)
                    {
                        headS = ptrnew;
                        ptrnew->next = ptrnew;
                        ptrnew->prev = ptrnew;
                    }
                    else if (headS->next == headS)//if 1 node presemt
                    {
                        ptrnew->next = headS;
                        headS->next = ptrnew;
                        headS->prev = ptrnew;
                        ptrnew->prev = headS;
                        headS = ptrnew;
                    }
                    else //if mutiple nodes present
                    {
                        stackList* ptrtemp = headS;
                        ptrnew->next = headS;
                        while (ptrtemp->next != headS)
                            ptrtemp = ptrtemp->next;
                        ptrnew->prev = ptrtemp;
                        ptrtemp->next = ptrnew;
                        headS = ptrnew;
                    }
                }
                else if (compare == ')') //if right parentheses
                {
                    while (headS->elementOPstack != '(')
                    {
                        postfixList* ptrnewrp = new postfixList;//adding
                        ptrnewrp->elementPostfix = headS->elementOPstack;
                        if (headP == NULL)
                        {
                            headP = ptrnewrp;
                            ptrnewrp->next = ptrnewrp;
                            ptrnewrp->prev = ptrnewrp;
                        }
                        else if (headP->next == headP)//if 1 node presemt
                        {
                            ptrnewrp->next = headP;
                            headP->next = ptrnewrp;
                            headP->prev = ptrnewrp;
                            ptrnewrp->prev = headP;
                            headP = ptrnewrp;
                        }
                        else //if mutiple nodes present
                        {
                            postfixList* ptrtemp = headP;
                            ptrtemp->prev = ptrnewrp;
                            ptrnewrp->next = headP;
                            while (ptrtemp->next != headP)
                                ptrtemp = ptrtemp->next;
                            ptrnewrp->prev = ptrtemp;
                            ptrtemp->next = ptrnewrp;
                            headP = ptrnewrp;
                        }
                        
                        stackList* ptrdel2 = headS;//popping

                        if (ptrdel2->next == NULL)
                        {
                            delete ptrdel2;
                        }
                        else
                        {
                            (ptrdel2->next)->prev = ptrdel2->prev;
                            (ptrdel2->prev)->next = ptrdel2->next;
                            headS = ptrdel2->next;
                            delete ptrdel2;
                        }
                    }
                    stackList* ptrdel3 = headS;//popping
                    (ptrdel3->next)->prev = ptrdel3->prev;
                    (ptrdel3->prev)->next = ptrdel3->next;
                    headS = ptrdel3->next;
                    delete ptrdel3;
                }

                else //if operand
                {
                    postfixList* ptrnew = new postfixList;
                    ptrnew->elementPostfix = compare;
                    if (headP == NULL)
                    {
                        headP = ptrnew;
                        ptrnew->next = ptrnew;
                        ptrnew->prev = ptrnew;
                    }
                    else if (headP->next == headP)//if 1 node presemt
                    {
                        ptrnew->next = headP;
                        headP->next = ptrnew;
                        headP->prev = ptrnew;
                        ptrnew->prev = headP;
                        headP = ptrnew;
                    }
                    else //if mutiple nodes present
                    {
                        postfixList* ptrtemp = headP;
                        ptrnew->next = headP;
                        while (ptrtemp->next != headP)
                            ptrtemp = ptrtemp->next;
                        ptrnew->prev = ptrtemp;
                        ptrtemp->next = ptrnew;
                        headP = ptrnew;
                    }
                }
            }
        
    }
    void printlist()
    {
        postfixList* ptrdisplay = headP->prev;
        postfixList* check = headP->prev;
        do
        {
            cout << ptrdisplay->elementPostfix;
            ptrdisplay = ptrdisplay->prev;
        } while (ptrdisplay != check);
    }

    string postfixtostring(int leng) {
        string out;
        for (int i = 0; i < leng + 2; i++)
        {
            postfixList* ptrpost;
            ptrpost = headP;
            out[i] = ptrpost->elementPostfix;
            ptrpost = ptrpost->next;
        }
        return out;
    }

};

int main()
{
    stackInfix obj;
    string input;
    cout << "enter a string: ";
    getline(cin, input);
    obj.pushInfix('(');
    for (int i = 0; i < input.length(); i++)
    {
        obj.pushInfix(input[i]);
    }
    obj.pushInfix(')');
    obj.InfixToPostfix(input.length());
    cout << "\n\nanswer: ";
    obj.printlist();
}