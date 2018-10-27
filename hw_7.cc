#include <iostream>
using namespace std;

void _strcpy( char *dest, const char *src);
void _strcpy2 ( char *dest, const char *src);
int _strlen (const char* str);
int _strcmp( const char* str1, const char* str2);
char* _strstr(char *str1, char *str2); 
void _strcat(char* str1, const char* str2);
void _strncpy(char* dest, const char* src, int n);
void _strncat(char* str1, const char* str2, int n);
int _strncmp(const char* str1, const char* str2, int n);



int main() {

    const char* mysource = "demon king";
    cout << mysource[4] << endl;
    char mydestination[100];
    _strcpy(mydestination, mysource);
    cout << "_strcpy " << mydestination << endl;

    _strcpy2(mydestination, mysource);
    cout << "_strcpy2 " << mydestination << endl;

    int l = _strlen(mydestination);
    cout << "_strlen " << l << endl;

    const char *s1 = "tricksters";
    const char *s2 = "trickster";

    cout << "S1 & S2 compare as follows : " <<_strcmp(s1,s2)<<endl;

    //hw starts

    char test[100] = "append_to_";
    
    //declaration of int for functions that will require it as input
    int n = 1;

    //strcat function
    
    cout << "_strcat: ";
    _strcat(test, s2);

    cout << endl;

    //chars for _strstr function
    char str1[20] = "hello_there";
    char str2[20] = "ello_";

    cout << "_strstr: "; 
    _strstr(str1,str2);
    cout << endl;

    
    //calling _strncat 
    cout << "_strncat: ";
    _strncat(test,s2, n); //function for concat for an n number of elements

    //calling _strncpy
    _strncpy(mydestination, mysource, n); //function for copying of an n number of elements

    cout << "_strncpy: " << mydestination << endl;

    //calling _strncmp
    cout << "_strncmp: S1 and S2 compare as follows:" << _strncmp(s1, s2, n) << endl;

    return 0;
}

// example of string copy operation
void  _strcpy(char *destination, const char *source) {

    int i=0;
    while(source[i]) {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
}

//more elegant implementation of string copy
void _strcpy2(char *destination, const char *source) {

   //check if source is not null and destination is not null
   while(((*destination++) = (*source++)));
}

//example implementation of string length.
int _strlen(const char* str) {

    int len=0;
    while(*str++) len++;
    
    return len;
}
//example implementation of string compare
int _strcmp(const char* s1, const char* s2) {

 while(*s1 && (*s1 == *s2))
 {
     s1++;
     s2++;

 }
 return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

//Fill in this method so that calling _stracat can append s2 contents to s1
void _strcat(char* s1, const char* s2) 
{
    int l, l2; //define int to hold lengths of char s1 and s2
    l = _strlen(s1); //get len of char s1 - this is needed to know where to start appending to
    
    l2 = _strlen(s2); //get len of char s2 - this is needed when to stop the loop for appending

    int i = 0;
    for (int i = 0; i < l2; i++, l++)
    {
        s1[l] = s2[i]; //append first char of s2 to element after last element of s1, then increase
        //elements until s2 is looped through

    }
    s1[l] = '\0'; //add null terminator to s1, because it was overwritten during the for loop
    cout << s1 << endl;


}
//check if string s2 is inside or embedded within string s1
char* _strstr(char *s1, char *s2) {
    //get len of s2
    //loop through each element of s1, to see if s2 elements are present
    //if all elements are present, the s2 string is there

    int l = _strlen(s1);
    int l2 = _strlen(s2);
    bool embedded = false;
    for (int i = 0; i < l; i++)
    {
        //enter first character of array
        int count = 0; //set count = 0. This count is needed to match the len of the string l2. 
        for (int j = 0; j < l2; j++)
        {//this loop is to compare each character of s2 to each character of s1. 
            
            if (s1[i] == s2[j])
            {
                i++; //increase i if we see a match - we need to compare the next element in s1 to the nexzt element in s2
                count ++; //increase count to see if a certain number of characters match
                if (count == l2)
                {
                    cout << "match found" << endl;
                    return s1;

                }
            }
            else if (s1[i] != s2[j]) //for efficiency. If an element of s1 does not match the element of s2, go to the next element of s1.
            {
                
                i = i - count; //revert count back so the match length does not get shorter
                break;
            }

        }
    }
            
cout << "Match not found " << endl;
return s1;
}
// _strcpy for specified number of characters n.
void _strncpy(char *destination, const char* source, int n) 
{
    int l = _strlen(source);
    int i=0;
    while(source[i] && i < n) {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';

}
// _strcmp for specified number of characters n.
int _strncmp(const char* s1, const char*s2, int n) {
    int i = 0;
    while (*s1 && (*s1 == *s2) &&  i < n)
    {
        s1++;
        s2++;
        i++;
        //why do we need pointers in this function
    }
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}
// _strcat for specified number of characters n.
void _strncat(char* s1, const char *s2, int n) 
{
    int l, l2; //define int to hold lengths of char s1 and s2
    l = _strlen(s1); //get len of char s1 - this is needed to know where to start appending to
    
    l2 = _strlen(s2); //get len of char s2 - this is needed when to stop the loop for appending

    int i = 0;
    for (int i = 0; i < n; i++, l++)
    {
        s1[l] = s2[i]; //append first char of s2 to element after last element of s1, then increase
        //elements until s2 is looped through until n chars

    }
    s1[l] = '\0'; //add null terminator to s1, because it was overwritten during the for loop
    cout << s1 << endl;
}