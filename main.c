
#include <stdio.h>
#include <string.h>

char cyphertext[]="WKH HDVLHVW PHWKRG RI HQFLSKHULQJ D WHAW PHVVDJH LV WR UHSODFH HDFK FKDUDFWHU EB DQRWKHU XVLQJ D ILAHG UXOH, VR IRU HADPSOH HYHUB OHWWHU D PDB EH UHSODFHG EB G, DQG HYHUB OHWWHU E EB WKH OHWWHU H DQG VR RQ.";
char alphabet[]="abcdefghijklmnopqrstuvwxyz";

// affine letter shift = (a*x + b) % 26
// thus the caesar letter shift = (1*x + a) % 26
int shift = 23; 

int a = 5;
int b = 3;

// vigenere cipher key
char keyword[]="babacabab";

// letter frequency table
struct letter_frequency {
  char * letter;
  int count;
} letter_tab[26];


/*
encription for:
caesar shift
affine
vegenere

helpful functions such as:
removing spaces
print backwards
*/
int main(void) 
{
    int i;
    char * name = "Your Name\0";
    char * thin = "\0";

    // keeping spaces, printing backwards
    // using sprintf when written as a function
    printf("Hello %s, ", name);
    removing_spaces(name);
    printf(" or ");
    display_backwards(name);

  // display the text
  // 
  printf("\nThe cypher challenge text is :\n");
  for (i = 0; i < strlen(cyphertext); i++){
    if (i%30 == 0) printf("\n");
    printf("%c", cyphertext[i]);
  }

    printf("\n\n");
    printf("[We think we know: \"WKH\" is \"the\"]\n");
    printf("[We are trying . : \"D\" as \"a\" and \"V\" as \"s\"]\n");

    printf("\nAaand, translated the text is :\n");

    // substituting the new alphabet
    // using cyphertext & cypherbet as parameters
    for (i=0; i<strlen(cyphertext); i++){
      // formatting
      //if (i%30 == 0) printf("\n");

      // translated letters
      if (cyphertext[i] == 'W') printf("t"); else
      if (cyphertext[i] == 'K') printf("h"); else
      if (cyphertext[i] == 'H') printf("e"); else

      // trying these ones
      if (cyphertext[i] == 'D') printf("a"); else
      if (cyphertext[i] == 'V') printf("s"); else

      // display the letter we don't know yet
      printf("%c", cyphertext[i]);
    }
    printf("\n");

    // caesar shift (phrase & shift as parameters)
    // using sprintf when written as a function
    printf("\nAlphabet with a Caesar shift\n");
    for (i = 0; i < strlen(alphabet); i++) {
      printf("%c", alphabet[i]);
      printf(" -> %c, ",alphabet[((i + shift) % 26)]);
    }
    printf("\n");

    // affine cipher (phrase & a/b as parameters)
    // using sprintf when written as a function
    printf("\nAlphabet with an affine shift\n");
    for (i = 0; i < strlen(alphabet); i++) {
      printf("%c", alphabet[i]);
      printf(" -> %c, ",alphabet[((a*i + b) % 26)]);
    }
    printf("\n");

    // vigenere cipher (phrase & keyword as parameters)
    // call caesar shift for each letter when written as a function
    printf("\nAlphabet with keyword shift\n");
    int j = 0;
    for (i = 0; i < strlen(alphabet); i++) {
      printf("%c", alphabet[i]);

      char *pos = strchr (alphabet, keyword[ j++ ]);
      int shift = pos ? pos - alphabet : -1;
      
      printf(" -> %c, ",alphabet[((i + shift) % 26)]);
      if (j == strlen(keyword)) j = 0;
    }
    printf("\n");

    return 0;
} 

char * remove_spaces(char * phrase){
    // removing spaces, printing forward
    // using sprintf when written as a function
    char * ret;
    for (int i = 0; i < strlen(phrase); i++) {
      if (phrase[i] != ' ') sprintf(ret, "%c", phrase[i]);
    }
    return * ret;  
}


int removing_spaces(char name[]){
    // removing spaces, printing forward
    for (int i = 0; i < strlen(name); i++) {
      if (name[i] != ' ') printf("%c", name[i]);
    }
    printf(" or ");
    return 0;
}

int display_backwards(char name[]){
    // keeping spaces, printing backwards
    for (int i = strlen(name); i >= 0; i--) {
      printf("%c", name[i]);
    }
     printf("\n");
     return 0;
}

int * keyword_shifts(char keyword[], char alphabet[]){
    // converting keyword to alphabetic indexes
    // for shifting each message letter with the 
    // caesar cipher
    int * ret;
    printf("Vigenare shifts are: ");
    for (int i = 0; i < strlen(keyword); i++) {
      char *pos = strchr (alphabet, keyword[i]);
      int position = pos ? pos - alphabet : -1;
      printf("%d ", position);
    }
     printf("\n");
     return ret;
}

int display_plaintext(char cyphertext[]){
 
  printf("\nThe cypher challenge text is :\n");
  for (int i = 0; i < strlen(cyphertext); i++){
    if (i%30 == 0) printf("\n");
    printf("%c", cyphertext[i]);
  }
  return 0;
}

int display_shifted_alphabet(char alphabet[], int shift){
  
    printf("\nAlphabet with a Caesar shift\n");
    for (int i = 0; i < strlen(alphabet); i++) {
      printf("%c", alphabet[i]);
      printf(" -> %c, ",alphabet[((i + shift) % 26)]);
    }
    printf("\n");
    return 0;
}

int display_affine_alphabet(char alphabet[], int a, int b){
  
    printf("\nAlphabet with an affine shift\n");
    for (int i = 0; i < strlen(alphabet); i++) {
      printf("%c", alphabet[i]);
      printf(" -> %c, ",alphabet[((a*i + b) % 26)]);
    }
    printf("\n");
    return 0;
}

int display_keyword_alphabet(char alphabet[], char keyword[]){
    printf("\nAlphabet with keyword shift\n");
    int j = 0;
    for (int i = 0; i < strlen(alphabet); i++) {
      printf("%c", alphabet[i]);

      char *pos = strchr (alphabet, keyword[ j++ ]);
      int shift = pos ? pos - alphabet : -1;
      
      printf(" -> %c, ",alphabet[((i + shift) % 26)]);
      if (j == strlen(keyword)) j = 0;
    }
    printf("\n");
    return 0;
}
