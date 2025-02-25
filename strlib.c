#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stddef.h> //array
#include <stdlib.h>//malloc() free()
#include <ctype.h>
int all_letters(char *s);//done
int num_in_range(char *s1,char b,char t);//done
int diff(char *s1,char *s2);//done
void shorten(char *s,int newLen);//done
int len_diff(char *s1,char *s2);//done but s1-s2 or s2-s1
void rm_left_space(char *s);//done but array style
void rm_right_space(char *s);//done
void rm_space(char*s);//done
int find(char *h,char *n);//done
char *ptr_to(char *h,char *n);//done
int is_empty(char *s);//done
char *str_zip(char *s1,char *s2);//done
void capitalize(char *s);//done but only from second word
int strcmp_ign_case(char *s1,char *s2);//done
void take_last(char *s,int n);//done but calls rm_left_space
char *dedup(char *s);
char *pad(char *s,int d);//done
int ends_with_ignore_case(char *s,char *suff);//done
char *repeat(char *s,int x,char sep);//done
char *replace(char *s,char *pat,char *rep);
char *str_connect(char **strs,int n,char c);
void rm_empties(char **words);
char **str_chop_all(char *s,char c);

int main(void)
{
    return 0;
}
int all_letters(char *s){
    //all caps or lowercase
    char*ptr=s;
    int result=0;
    while(*ptr&&*ptr>64&&*ptr<91){
        ptr++;
        if(*ptr>90)
            return 0;
        result=1;
    }
    while(*ptr&&*ptr>96&&*ptr<123){
        ptr++;
        if(*ptr<97)
            return 0;
        result=1;
    }
    return result;
}
int num_in_range(char *s1,char b,char t){
    char*ptr=s1;
    int count=0;
    while(*ptr){
        if(*ptr>b&&*ptr<t)
            count++;
        ptr++;
    }
    return count;
}
int diff(char *s1,char *s2){
    char*p1=s1;
    char*p2=s2;
    int count=0;
    while(*p1&&*p2){
        if(*p1!=*p2)count++;
        p1++;
        p2++;
    }
    char*ptr=*p1?p1:p2;
    while(*ptr){
        count++;
        ptr++;
    }
    //returns the number of positions in which s1 and s2 differ, i.e., it returns the number of changes that would need to be made in order to transform s1 into s2, where a change could be a character substitution, an insertion, or a deletion.
    return count;
}
void shorten(char *s,int newLen){
    char*end=s+newLen;
    if(!*end)return;
    *end='\0';
}
int len_diff(char *s1,char *s2){
    //Returns the length of s1 - the length of s2
    char*p1=s1;
    char*p2=s2;
    int count=0;
    while(*p1&&*p2){
        p1++;
        p2++;
    }
    char*ptr=*p1?p1:p2;
    while(*ptr){
        count++;
        ptr++;
    }
    return count;
}
void rm_left_space(char *s){
    //removes whitespace characters from the beginning of s
    char*ptr=s;
    int start=0;
    int end=0;
    while(*ptr){
        if(*(ptr++)==' ')
            start++;
        end++;
    }
    for(int i=0;i<end-start;i++){
        s[i]=s[start+i];
    }
    s[end-start]='\0';
}
void rm_right_space(char *s){
    char*ptr=s;
    while(*ptr!=' '){
        ptr++;
    }
    *ptr='\0';
    //removes whitespace characters from the end of s
}
void rm_space(char*s){
    //removes whitespace characters from the beginning and the ending s
    char*ptr=s;
    int start=0;
    while(*ptr==' '){
        start++;
        ptr++;
    }
    int end=start;
    while(*ptr!=' '){
        end++;
        ptr++;
    }
    *ptr='\0';
    for(int i=0;i<end-start;i++){
        s[i]=s[start+i];
    }
    s[end-start]='\0';
}
int find(char *h,char *n){
    //returns the index of the first occurence of n in the string h or -1 if it isn't found.
    char*ptr=h;
    int index=0;
    while(*ptr){
        if(*ptr==*n){
            return index;
        }
        ptr++;
        index++;
    }
    return -1;
}
char *ptr_to(char *h,char *n){
    //returns a pointer to the first occurence of n in the string h or NULL if it isn't found
    char*ptr=h;
    while(*ptr){
        if(*ptr==*n){
            return ptr;
        }
        ptr++;
    }
    return NULL;
}
int is_empty(char *s){
    //returns 1 if s is NULL, consists of only the null character ('') or only whitespace. returns 0 otherwise.
    if(!*s)return 1;
    char*ptr=s;
    while(*ptr){
        if(*ptr!=' ')return 0;
        ptr++;
    }
    return 1;
}
char *str_zip(char *s1,char *s2){
    //Returns a new string consisting of all of the characters of s1 and s2 interleaved with each other. For example, if s1 is "Spongebob" and s2 is "Patrick", the function returns the string "SPpaotnrgiecbkob"
    char*p1=s1;
    char*p2=s2;
    int len1=0;
    int len2=0;
    while(*(p1++)){
        len1++;
    }
    while(*(p2++)){
        len2++;
    }
    printf("%d %d\n",len1,len2);
    char*str=malloc(len1+len2);
    char*p3=str;
    p1=s1;
    p2=s2;
    while(*p1&&*p2){
        *(p3++)=*(p1++);
        *(p3++)=*(p2++);
    }
    return str;
}
void capitalize(char *s){
    //Changes s so that the first letter of every word is in upper case and each additional letter is in lower case.
    char*ptr=s;
    while(*ptr){
        if(*(ptr++)==' '&&(*ptr>96&&*ptr<123)){
            *ptr-=32;
        }
    }
}
int strcmp_ign_case(char *s1,char *s2){
    //Compares s1 and s2 ignoring case. Returns a positive number if s1 would appear after s2 in the dictionary, a negative number if it would appear before s2, or 0 if the two are equal.
    char*p1=s1;
    char*p2=s2;
    while(*p1||*p2){
        if(*p1!=*p2){
            return *p1-*p2;
        }
        p1++;
        p2++;
    }
    return 0;
}
void take_last(char *s,int n){
    //Modifies s so that it consists of only its last n characters. If n is ≥ the length of s, the original string is unmodified. For example if we call take_last("Brubeck" 5), when the function finishes, the original string becomes "ubeck"
    int len=0;
    char*ptr=s;
    while(*(ptr++)){
        len++;
    }
    if(n>=len)return;
    ptr=s;
    for(int i=0;i<len-n;i++){
        *(ptr++)=' ';
    }
    rm_left_space(s);
}
char *dedup(char *s){
    //returns a new string based on s, but without any duplicate characters. For example, if s is the string, "There's always money in the banana stand.", the function returns the string "Ther's alwymonitbd.". It is up to the caller to free the memory allocated by the function.
    char*ptr=s;
    int len=0;
    while(*ptr){
        len++;
        ptr++;
    }
    ptr=s;
    char*str=malloc(len);
    ptr=s;
    return NULL;
}
char *pad(char *s,int d){
    //returns a new string consisting of all of the letters of s, but padded with spaces at the end so that the total length of the returned string is an even multiple of d. If the length of s is already an even multiple of d, the function returns a copy of s. The function returns NULL on failure or if s is NULL. Otherwise, it returns the new string. It is up to the caller to free any memory allocated by the function.
    if(!*s)return NULL;
    char*ptr=s;
    int len=0;
    while(*ptr){
        len++;
        ptr++;
    }
    int remainder=len%d;
    if(!remainder){
        return s;
    }
    char*str=malloc(len+remainder);
    char*p2=str;
    ptr=s;
    for(int i=0;i<len+remainder;i++){
        if(*ptr){
            *p2=*ptr;
            ptr++;
        }
        else
            *p2=' ';
        p2++;
    }
    return str;
}
int ends_with_ignore_case(char *s,char *suff){
    //returns 1 if suff is a suffix of s ignoring case or 0 otherwise.
    char*p=s;
    char*pSuff=suff;
    while(*p){
        p++;
    }
    while(*pSuff){
        pSuff++;
    }
    while(*(--pSuff)){
        if(*(--p)!=*pSuff)
            return 0;
    }
    return 1;
}
char *repeat(char *s,int x,char sep){
    //Returns a new string consisting of the characters in s repeated x times, with the character sep in between. For example, if s is the string all right, x is 3, and sep is , the function returns the new string all right,all right,all right. If s is NULL, the function returns NULL. It is up to the caller to free any memory allocated by the function.
    if(!s)return NULL;
    int len=0;
    char*ptr=s;
    while(*(ptr++)){
        len++;
    }
    char*str=malloc(len);
    char*p2=str;
    ptr=s;
    while(x){
        if(*ptr){
            *p2=*(ptr++);
        }
        else{
            ptr=s;
            *p2=sep;
            x--;
        }
        p2++;
    }
    return str;
}
char *replace(char *s,char *pat,char *rep){
    //Returns a copy of the string s, but with each instance of pat replaced with rep, note that len(pat) can be less than, greater than, or equal to len(rep). The function allocates memory for the resulting string, and it is up to the caller to free it. For example, if we call replace("Fiore X", "X", "sucks"), what is returned is the new string Fiore sucks (but remember, pat could be longer than an individual character and could occur multiple times).
    char*p1=s;
    int len1=0;
    while(*(p1++)){
        len1++;
    }
    char*p2=pat;
    int len2=0;
    while(*(p2++)){
        len2++;
    }
    char*p3=rep;
    int len3=0;
    while(*(p3++)){
        len3++;
    }
    int diff=len3-len2;
    int count=0;
    while(*p1){
        if(!*p2){
            p2=pat;
            count++;
        }
        if(*p1==*p2){
            p2++;
        }
        p1++;
    }
    char*str=malloc(diff*count+len1);
    char*p4=str;
    p1=s;
    p2=pat;
    p3=rep;
    return NULL;
}
char *str_connect(char **strs,int n,char c){
    //Returns a string consisting of the first n strings in strs with the character c used as a separator. For example, if strs contains the strings {"Washington", "Adams", "Jefferson"} and c is '+', the function returns the string "Washington+Adams+Jefferson"
    return NULL;
}
void rm_empties(char **words){
    //words is an array of string terminated with a NULL pointer. The function removes any empty strings (i.e., strings of length 0) from the array.
}
char **str_chop_all(char *s,char c){
    //Returns an array of string consisting of the characters in s split into tokens based on the delimeter c, followed by a NULL pointer. For example, if s is "I am ready for a nice vacation" and c is ' ', it returns {"I", "am", "ready", "for", "a", "nice", "vacation", NULL}
    return NULL;
}
