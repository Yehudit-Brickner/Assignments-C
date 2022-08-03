

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TXT 1024
#define WORD 30
#define MAX 1024





void Gematria (char *key, char *str){

   

    int g_key = 0;

    char *pkey = key;
    char *pstr = str;

    char num = 0;
    int i = 0;
    while (i != strlen(pkey)){
        num = pkey[i];
        if (num <= 90 && num >= 65){
            g_key = g_key + num - 64;
        }
        if (num <= 122 && num >= 97){
            g_key = g_key + num - 96;
        }
        i++;
    }
    


    num = 0;
    int g_count=0;
    char* words=malloc(MAX);
    if(!words){
        printf("no memory was allocated");
    }
    memset(words,0,strlen(words));
    i=0;
    int j=0;
    int k=0;
    int count =0;
    int length=strlen(pstr);
    
    printf("Gematria Sequences: ");
    
    while(i<length){
        //find word/letters that have the same value
        //find the gimatria value of the char
        num = pstr[i];
        if (num <= 90 && num >= 65){
            num=num-64;
        }
        else if (num <= 122 && num >= 97){
            num= num - 96;
        }
        else{
            num= (-1); 
        }
        // if the value is smaller then the key wirds gimatria  
        if(num<=g_key && num!=-1){
            words[j]=pstr[i];
            g_count=g_count+num;
            // if the gumatria of all the letters added is bigger than the key gimatria get rid of the first not empty char
            while(g_count>=g_key){   
                char num1= words[k];
                if(g_count>g_key){
                    if (num1 <= 90 && num1>= 65){
                        num1=num1-64;
                    }
                    else if (num1 <= 122 && num1 >= 97){
                        num1= num1 - 96;
                    }
                    else{
                        num1= (-1); 
                    }
                
                    if(num1!=-1){
                        g_count=g_count-num1;
                        // words[k] = "";
                        k++;
                    }  
                    else {
                        //words[k] = "";
                        k++;
                    }
                }  
                else{
                    if (num1 <= 90 && num1>= 65){
                        num1=num1-64;
                        break;
                    }
                    else if (num1 <= 122 && num1 >= 97){
                        num1= num1 - 96;
                        break;
                    }
                    else{
                        num1= (-1); 
                    }
                
                    if(num1==-1){
                        words[k] = ' ';
                        k++;
                    }     
                }
            }
            // if the gumatria of all the letters added is equal to the key gimatria print the string
    
            if(g_count==g_key && num>0){
                
                if(count==0){
                    for(int l=k;l<=j;l++){
                        printf("%c", words[l]);
                    }
                    
                }
                if(count>0){
                    printf("~");
                    for(int l=k;l<=j;l++){
                        printf("%c", words[l]);
                    }
                }
                count=count+1;
            }

            i++;
            j++;    
        }
        // if the value is bigger then the key words gimatria restart the string 
        else if (num>g_key){
            memset(words,0,strlen(words));
            g_count=0;
            j=0; 
            k=0;
            i++;   
            }
         // if the char we are at, isnt a letter add it to the string    
        else{
            words[j] =pstr[i]; 
            i++;
            j++;
        }
    }

    printf("\n");
    free(words) ;   
}




char *atbashCipher(char *key){
    int i=0;
    
   // char atbashWord[WORD] = (char)malloc(sizeof(char)*WORD);
    char* atbashWord=malloc(strlen(key));
    if(!atbashWord){
        printf("no memory was allocated");
    }
    memset(atbashWord,0,strlen(atbashWord));
    //printf("Atbash Cipher code\n");
   // while(key[i] != '\0' || i <= WORD){
       while (i<strlen(key)){
        if(!((key[i] >= 0 && key[i] < 65) || (key[i] > 90 && key[i] < 97) || (key[i] > 122 && key[i] <= 127)))
        {
            if(key[i] >= 'A' && key[i] <= 'Z')
                atbashWord[i] = 'Z'+'A'-key[i];
            if(key[i] >= 'a' && key[i] <= 'z')
                atbashWord[i] = 'z'+'a'-key[i];
        }
        else{
            atbashWord[i] = key[i]; 
        } 
        if((atbashWord[i] >=0 && atbashWord[i] < 65) || (atbashWord[i] > 90 && atbashWord[i] < 97) || (atbashWord[i] > 122 && atbashWord[i] <= 127)){
            //printf("%c",atbashWord[i]);    
        }
        i++;
    }
    atbashWord[i] = '\0';   //end of the word
    return atbashWord;
}



char *reverseStr(char *str)  
{  //reverse the string
    int i=0, len;  
    len = strlen(str);
    char *strNew = ((char *)malloc(sizeof(char)*len));     
    for (i = 0; i < len && str[i] != '\0'; i++)  {  
        strNew[i] = str[len - i - 1];    
    }
    strNew[i] = '\0';
    return strNew;
}  


void Atbash(char *word, char *text){
    char *atbashWord = atbashCipher(word);
    char *reverseAtbashWord = reverseStr(atbashWord);
    printf("Atbash Sequences: ");
    int tiltdaPrint = 0;
    int i = 0;

    while (text[i] != '\0'){
        if (text[i] == atbashWord[0]){
            int flag = 0;
            int j = i;
            int k = 0;
            while (text[j] != '\0' && atbashWord[k] != '\0' && k >= 0) {
                if ((text[j] >= 'a' && text[j] <= 'z') || (text[j] >= 'A' && text[j] <= 'Z')){
                    if (text[j] == atbashWord[k]){
                        ++k;
                        if (atbashWord[k] == '\0') {
                            flag = 1;
                            k = -1;
                        }
                    }
                    else{
                        k = -1;
                    }
                }
                ++j;
            }
            --j;
            if (flag) {
                if (tiltdaPrint){
                    printf("~");
                }
                for (int k = i; k <= j; k++){
                    printf("%c", text[k]);
                }
                ++tiltdaPrint;
            }
        }
        else if (text[i] == reverseAtbashWord[0]){
            int flag = 0;
            int j = i;
            int k = 0;
            while (text[j] != '\0' && reverseAtbashWord[k] != '\0' && k >= 0) {
                if ((text[j] >= 'a' && text[j] <= 'z') || (text[j] >= 'A' && text[j] <= 'Z')) {
                    if (text[j] == reverseAtbashWord[k]){
                        ++k;
                        if (reverseAtbashWord[k] == '\0'){
                            flag = 1;
                            k = -1;
                        }
                    }
                    else{
                        k = -1;
                    }
                }
                ++j;
            }
            --j;
            if (flag){
                if (tiltdaPrint){
                    printf("~");
                }
                for (int l = i; l <= j; l++){
                    printf("%c", text[l]);
                }
                ++tiltdaPrint;
            }
        }
        ++i;
    }

    
/*    
    while (text[i] != '\0'){   //while the word isn't over
        if (text[i] == atbashWord[0]){ 
            int flag = 0;
            int j = i;
            int k = 0;
            while (text[j] != '\0' && atbashWord[k] != '\0' && k >= 0) {   //loop while it's a letter and the word isn't over
                if ((text[j] >= 'a' && text[j] <= 'z') || (text[j] >= 'A' && text[j] <= 'Z')){
                    if (text[j] == atbashWord[k]){
                        ++k;
                        if (atbashWord[k] == '\0') {
                            flag = 1;
                            k = -1;
                        }
                    }
                    else{
                        k = -1;
                    }
                }
                ++j;
            }
            --j;
            if (flag) {
                if (tiltdaPrint){
                    printf("~");
                }
                for (int l = i; l <= j; l++){
                    printf("%c", text[l]);
                }
                ++tiltdaPrint;
            }
        }
        else{
            if (text[i] == reverseAtbashWord[0]){
                int flag = 0;
                int j = i;
                int k = 0;
                while (text[j] != '\0' && reverseAtbashWord[k] != '\0' && k >= 0) {
                    if ((text[j] >= 'a' && text[j] <= 'z') || (text[j] >= 'A' && text[j] <= 'Z')) {
                        if (text[j] == reverseAtbashWord[k]){
                            ++k; 
                            if (reverseAtbashWord[k] == '\0'){
                                flag = 1;
                                k = -1;
                              
                            }
                        }
                        else
                            k = -1;
                    }
                ++j;
                }
                --j;
                if (flag){
                    if (tiltdaPrint){
                        printf("~");
                    }
                    for (int l = i; l <= j; l++){
                        printf("%c", text[l]);
                    }
                     ++tiltdaPrint;
                }
             }
             ++i;
        }
        i++;
    }
    */
        printf("\n");
        free(atbashWord);
        free(reverseAtbashWord);
}


  
/*
void Anagram (char *key,char *str){
    
    int g_key = 0;
    char *pkey = key;
    char *pstr = str;
    char num = 0;
    int i = 0;
    //int nums[strlen(pkey)];
    int* nums=malloc(strlen(pkey));
    if(!nums){
        printf("no meotry was allocated");
    }
    //calculating the gimatria of the key word
    while (i != strlen(pkey)){
        num = pkey[i];
        if (num <= 122 && num >= 97){
            g_key = g_key + num -96;
        }
        if (num <= 90 && num >= 65){
            g_key = g_key + num - 64;
        }
        
        nums[i]=num;
        i++;
    }
    //printf("%d\n", g_key);


    num = 0;
    int g_count=0;
    char* words=malloc(MAX);
    memset(words,0,strlen(words));
    i=0;
    int j=0;
    int k=0;
    int count =0;
    int length=strlen(pstr);
    
    printf("Anagram Sequences: ");
    while(i<length){
        //find the gimatria value of the char
        num = pstr[i];
        if (num <= 90 && num >= 65){
            num=num-64;
        }
        else if (num <= 122 && num >= 97){
            num= num - 96;
        }
        else{
            num= (-1); 
        }
        // if the value is smaller then the key words gimatria  
        if(num<=g_key && num!=-1){
            words[j]=pstr[i];
            g_count=g_count+num;
            // if the gumatria of all the letters added is bigger than the key gimatria get rid of the first not empty char
            // we will remove letters from the left till we are equal or under the gimatria of the key word.
            while(g_count>=g_key){   
                char num1= words[k];
                if(g_count>g_key){
                    if (num1 <= 90 && num1>= 65){
                        num1=num1-64;
                    }
                    else if (num1 <= 122 && num1 >= 97){
                        num1= num1 - 96;
                     }
                    else{
                        num1= (-1); 
                    }
                
                    if(num1!=-1){
                        g_count=g_count-num1;
                        words[k]=' ';
                        k++;
                    }  
                    else {
                        words[k]=' ';
                        k++;
                    }
                }  
                else{
                    if (num1 <= 90 && num1>= 65){
                        num1=num1-64;
                        break;
                    }
                    else if (num1 <= 122 && num1 >= 97){
                        num1= num1 - 96;
                        break;
                    }
                    else{
                        num1= (-1); 
                    }
                
                    if(num1==-1){
                        words[k]= ' ';
                        k++;
                    }     
                }    
            }
            i++;
            j++;
        }
 
        
        // if the value is bigger then the key words gimatria restart the string 
        else if (num>g_key){
            memset(words,0,strlen(words));
            j=0; 
            k=0;
            i++;   
            g_count=0;
        }
        // if the char we are at, isnt a letter add it to the string    
        else{
            words[j] =pstr[i]; 
            i++;
            j++;
        }



                
            // if the gimatria of all the letters added is equal to the key gimatria
            if(g_count==g_key){
               //check if all leters are in this word
               char *letters=malloc(strlen(pkey)*sizeof(int));
              //int letters[strlen(pkey)];
               memset(letters,0,strlen(letters));
               
               int print=0; // acting like a boolean 0=print, 1=dont print
               char c1=words[j-1];
               if(c1==32){
                   print=1;
               }
               for(int l=k;l<j && print==0;l++){
                   c1=words[l];
                   if((c1>=65 && c1<=90) || (c1>=97 && c1<=122) || (c1==32)){
                        for(int n=0;n<strlen(pkey);n++){
                            if(c1==pkey[n] && letters[n]!=1){
                                letters[n]=1;   
                            }
                        }
                   }
                   else{
                       print=1;
                   }
               }
               if(print==0){
                    for(int n=0;n<strlen(pkey);n++){
                        if(letters[n]==0){
                            print=1;
                        }
                    }
               }
               if(print==0){
               
                    // printf("same word number %d\n",count);
            
                    if(count==0){
                        for(int l=k;l<=j;l++){
                            printf("%c", words[l]);
                        }
                        // printf("\n");
                    }
                   else if(count>0){
                        printf("~");
                        for(int l=k;l<=j;l++){
                            printf("%c", words[l]);
                        }
                    }
                    count=count+1;
               }
            
            }
    
         
    }
    printf("\n"); 
    free(nums);
}

*/

void Anagram (char *key,char *str){

    int g_key = 0;
    char *pkey = key;
    char *pstr = str;
    char num = 0;
    int i = 0;
   // int nums[strlen(pkey)];
   int* nums=malloc(strlen(pkey));
    if(!nums){
        printf("no meotry was allocated");
    }
    //calculating the gimatria of the key word
    while (i != strlen(pkey)){
        num = pkey[i];
        if (num <= 122 && num >= 97){
            g_key = g_key + num -96;
            
        }
        else if (num <= 90 && num >= 65){
            g_key = g_key + num - 64;
            
        }
        else{
            if(num!=32){
                g_key=g_key+num;
                
            }
        }
        nums[i]=num;
        i++;
    }
    


    num = 0;
    int g_count=0;
    char* words=malloc(MAX);
    memset(words,0,strlen(words));
    i=0;
    int j=0;
    int k=0;
    int count =0;
    int length=strlen(pstr);

    printf("Anagram Sequences: ");
    while(i<length){
        //find the gimatria value of the char
        num = pstr[i];
        if (num <= 90 && num >= 65){
            num=num-64;
        }
        else if (num <= 122 && num >= 97){
            num= num - 96;
        }
        else{
           if(num==32){
                num= (-1); 
            }
        }
        // if the value is smaller then the key words gimatria  
        if(num<=g_key && num!=-1){
            words[j]=pstr[i];
            g_count=g_count+num;
            // if the gumatria of all the letters added is bigger than the key gimatria get rid of the first not empty char
            // we will remove letters from the left till we are equal or under the gimatria of the key word.
            while(g_count>g_key){   
                char num1= words[k];
                  if (num1 <= 90 && num1 >= 65){
                         num1=num1-64;
                    }
                    else if (num1 <= 122 && num1 >= 97){
                        num1= num1 - 96;
                        } 
                if(num1!=32){
                   g_count=g_count-num1;
                        words[k]=' ';
                        k++;  
                }
                else{
                    k++;
                }
                
                /*
                if(g_count>g_key){
                    if (num1 <= 90 && num1>= 65){
                        num1=num1-64;
                    }
                    else if (num1 <= 122 && num1 >= 97){
                        num1= num1 - 96;
                     }
                    else{
                      num1= (-1); 
                    }
                   
                    if(num1!=-1){
                        g_count=g_count-num1;
                        words[k]=' ';
                        k++;
                    }  
                    else {
                        words[k]=' ';
                        k++;
                    }
                     */
                }  
                /*
                //get rid of symbols at the beging of the word
                else{
                    if (num1 <= 90 && num1>= 65){
                        num1=num1-64;
                        break;
                    }
                    else if (num1 <= 122 && num1 >= 97){
                        num1= num1 - 96;
                        break;
                    }
                    //else{
                      //  num1= (-1); 
                    //}

                    if(num1==-1){
                        words[k]=' ';
                        k++;
                    }     
                }  
                */  
            
            
            // hopefully in correct spot
            i++;
            j++;
            }
          
            

        // if the value is bigger then the key words gimatria restart the string 
        else if (num>g_key){
            memset(words,0,strlen(words));
            j=0; 
            k=0;
            i++;   
            g_count=0;
        }

        // if the char we are at, isnt a letter add it to the string ,num=-1  
        else{
            words[j] =pstr[i]; 
            i++;
            j++;
        }


            // if the gimatria of all the letters added is equal to the key gimatria
            if(g_count==g_key){
               //check if all leters are in this word
              // char *letters=malloc(strlen(pkey)*sizeof(int));
                char *letters=malloc(strlen(pkey));
                memset(letters,0,strlen(letters));

               int print=0; // acting like a boolean 0=print, 1=dont print
               char c1=words[j-1];
               if(c1==32){
                   print=1;
               }
               int getrid=0; //flag
                int g=k; //counter
              while(getrid==0){
                  c1=words[g];
                  if(c1!=32){
                      getrid=1;
                  }
                  else{
                      k++;
                      g++;
                  }
              }
               for(int l=k;l<j && print==0;l++){
                   c1=words[l];
                   
                  // if((c1>=65 && c1<=90 )|| (c1>=97 && c1<=122) || c1==32){
                        if((c1>=65 && c1<=90 )){
                            c1=c1-64;
                        }
                        else if((c1>=97 && c1<=122)){
                            c1=c1-96;
                        }
                       // if(c1<97){
                         //   c1=c1+32;
                       // }
                        int added=0;
                        for(int n=0;n<strlen(pkey) && added==0 ;n++){
                            char c2=pkey[n];
                            if((c2>=65 && c2<=90 )){
                                c2=c2-64;
                                }
                            else if((c2>=97 && c2<=122)){
                                c2=c2-96;
                            }
                          //  if(c2<97){
                            //   c2=c2+32;
                           //}
                            if(c1==c2 && letters[n]!=1){
                                letters[n]=1; 
                                added=1; 
                            }
                        }
                        if(added==0){
                            if(c1!=32){
                                print=1;
                            }
                        }
                        
                       
                   //}
                   
                 
                   ///else{
                      // print=1;
                  // }
               }


               if(print==0){
                    for(int n=0;n<strlen(pkey);n++){
                        if(letters[n]==0){
                            print=1;
                        }
                    }
               }
               if(print==0){
                    if(count==0){
                        for(int l=k;l<j;l++){
                            printf("%c", words[l]);
                        }
                        
                    }
                    if(count>0){
                        printf("~");
                        for(int l=k;l<j;l++){
                            printf("%c", words[l]);
                        }
                    }
                    count=count+1;
               }

            }
    } 

}


int main(){

    

    char* key =malloc(WORD);
    if(!key){
        printf("no memory allocated");
    }
    memset(key,0,strlen(key));
   
    int i=0;
    char c1=0;
   // printf("enter word: ");
    while((c1=getchar())!=' ' && c1!='\t' && c1!='\n'){
        key[i++]=c1;   
    }
   // key[i++]='\0';
    //  printf("done\n");
    char* str=malloc(TXT);
    if(!str){
        printf("no memory aloocated");
    }
    memset(str,0,strlen(str));
  

    i=0;
    c1=0;
   // printf("enter txt: ");
    while((c1=getchar())!='~'){
        str[i++]=c1;
    }
   // str[i++]='\0';
    //printf("done\n");
    char *pkey=key;
    char *pstr=str;
    // printf("%s\n",str);

 
    //printf("\n");
    // printf("finished\n");

    Gematria (pkey, pstr);
    Atbash(pkey,pstr);
    Anagram (pkey,pstr);



free(str);
free(key);

    return 0;
}

