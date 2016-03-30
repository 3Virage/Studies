#ifndef array
#define array
typedef struct wez{
    char imie[16];
    char nazwisko[16];
    long numer1;
    long numer2;
    struct wez* left;
    struct wez* right;
    struct wez* up;
    }wezel;
    
void ClrScr(); 
wezel* create(wezel* up); 
void print(wezel* wezel); 
int compare(char pierwszy[16],char drugi[16]);
void insert(wezel* nowy,wezel*root);
void minimum(wezel* wezel);
void maximum(wezel* wezel);
void InOrder(wezel* root);
int find(wezel* root,char wyraz[16]);
int count(wezel* root);
int height(wezel* root);
#endif
