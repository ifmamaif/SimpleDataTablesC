#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <dirent.h>
#include <windows.h>
#include <ctype.h>

#define errortext "avoiderror"
#define keyword 'test'
#define MainDirectory "data"
#define LoginDirectory "data/login/"
#define ItemDirectory "data/item/"
#define PlayersDirectory "data/players/"
#define BonusDirectory "data/bonus/"
#define SpellDirectory "data/spell/"
#define ItemDirectory "data/item/"
#define PlayerDirectory "data/player/"


enum typeitem {
	Helmet,
	Earings,
	Necklace,
	BodyArmour,
	Belt,
	Leggings,
	Shoes,
	Bracelet,
	Ring,
	Weapon,
	Shield,
	Potion,
	Scroll,
	Book,
	Ammo,
	Shoulder,
	Wings,
	Object,
	Ore,
	Currency,
	Map,
	Vanity_items,
	Tool,
	Plant,
	Soil,
	Block,
	Paint,
	Material,
	Soul,
	Seed,
	Key,
	Furniture,
	typeitemEND
};
enum typeModifier {
	Common,
	Rare,
	Unique,
	Personalized,
	Broken,
	Demonic,
	Legendary,
	Mystic,
	Elemental,
	Heavy,
	Deadly,
	Tiny,
	Sharp,
	Massive,
	Lightly,
	Terrible
};
enum TypeBonus {
	
};
enum TypeSpell {
	
};
enum typeAI	{
	NPC,
	Mounts,
	Pets,
	Minion,
	Enemies,
	Boss,
	Summon,
	Player	
};
struct Account {
	char Username[30];
	char Password[30];
	char Email[30];
	char Character[30];
};
struct Bonus {
	char ID[3];
	char Name[50];
	int TypeBonus;
	int value;
	int IsPercent;
};
struct Spell {
	char ID[3];
	char Name[30];
	int TypeSpell;
	int Cooldown;
	char Bonuses[30];//struct Bonus *Bonuses;
};
struct Item { 
	char ID[3];
	char Name[30];
	int TypeItem;	
	int HealthPoint;
	int Weight;
	int Sharp;
	char Bonuses[30];//struct Bonus *Bonuses;
};
struct Equipment {
	Item MainHand;
	Item SecondHand;	
	Item Helmet;
	Item BodyArmour;
	Item Belt;
	Item Leggings;
	Item Shoes;	
	Item Necklace;	
	Item Earing1;
	Item Earing2;
	Item Bracelet1;
	Item Bracelet2;
	Item Ring1;
	Item Ring2;
	Item Ring3;
	Item Ring4;
	Item Ring5;
	Item Ring6;
	Item Ring7;
	Item Ring8;
	Item Ring9;
	Item Ring10;
};
struct AI { // ?
	char *Name;
	int ID;
	int type;
	int HealthMax;
	int HealthCurrent;
	int ManaMax;
	int ManaMin;
	int Attack;
	int AttackSpeed;
	int Defense;
	int MovementSpeed;
};
struct Player { 
	char Account[30];
	char Username[30];
	int Level;
	int HP;
	int Mana;
	int Vitality;
	int Strength;
	int Agility;
	int Intelligence;
	int Defense;
	int MovementSpeed;
	char Equipment[30];	//	struct Equipment Equipment;
	char Inventory[30];	//	struct Item *Inventory;
};
struct VectPointer {
	void (*functiedeordonare)(char*Order);
};
int isnumber(char *aux){
	int i=0;
	while(aux[i]!='\0'){
		if(aux[i]<'0' || aux[i]>'9') return 0;
		i++;
	}
	return 1;	
}
int convertstringtoint(char *s){
	int dec = 0, i, j, len;
	//printf("Enter a number: ");
	for(i=0; i<strlen(s); i++){
		dec =dec*10 +(s[i]-'0');
		//printf("%d\n",dec);
	}
	//printf("%d",dec);
	return dec;
}
int citestenumber(){
	char number[9];
	scanf("%s",&number);
	if(isnumber(number)==1)
		{
			return convertstringtoint(number);
		}
	return -1;
}void createdirectory(char *thisdirectory);
std::ifstream::pos_type filesize(const char* filename){
    std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
    return in.tellg(); 
}
int numarcifre(int n){
	if(n!=0){
	int i=0;
	while(n>0)
	{
		n/=10;
		i++;
	}
	return i;
	}
	return 1;
}

char* getinfo(char * fcontent,int size,FILE *f);
void avoiderror();
void displayaccounts(struct Account *ThisArray,int size);
void crypt(char *text);
void decrypt(char *text);
void deletefile(char *Directory);
void deleteall(char * Directory);
void change(int where,int what,char*Directory);

void Add(int what,char*Directory);
void Check(int where,char*Directory);

void afisaccount(int buffer, int ID,const char *Username,char * fcontent,int size,FILE *f);
void listaccounts(char*Directory);
void afisbonus(int buffer,struct Bonus *ThisBonus,int size);
void listbonuses(char*Directory);
void afisspell(int buffer,struct Spell *ThisSpell,int size);
void listspells(char*Directory);
void afisitem(int buffer,struct Item *ThisItem,int size);
void listitems(char*Directory);
void afisplayer(int buffer,struct Player *ThisPlayer,int size);
void listplayers(char*Directory);

void orderaccount(char* Order);
void orderbonus(char* Order);
void orderspell(char* Order);
void orderitem(char* Order);
void orderplayer(char* Order);
static int compareaccountEmail (const void * a, const void * b);
static int compareaccountCharacter (const void * a, const void * b);
static int comparebonusName (const void * a, const void * b);
static int comparebonusTypeBonus (const void * a, const void * b);
static int comparespellName (const void * a, const void * b);
static int comparespellTypeSpell (const void * a, const void * b);
static int compareitemName (const void * a, const void * b);
static int compareitemTypeItem (const void * a, const void * b);
static int compareplayeraccount (const void * a, const void * b);
void alege();

int main(){	
	alege();
	return 0;
}

void createdirectory(char *thisdirectory){
	mkdir(thisdirectory);
}
void displayaccounts(struct Account *ThisArray,int size,int buffer){
	int i,j;
	for(i=0;i<5*buffer;i++)
	printf("=");
	printf("\n");
	printf("=");	
	for(i=0;i<(buffer-strlen("ID")-2)/2;i++)
		printf(" ");
	printf("%s","ID");
	for(i=0;i<(buffer-strlen("ID")-2)/2;i++)
		printf(" ");
	printf("=");	
	printf("=");
	for(i=0;i<(buffer-strlen("Username")-2)/2;i++)
		printf(" ");
	printf("Username");
	for(i=0;i<(buffer-(strlen("Username")%2==0?(strlen("Username")):(strlen("Username")-1))-2)/2;i++)
		printf(" ");
	printf("=");
	printf("=");
	for(i=0;i<(buffer-strlen("Password")-2)/2;i++)
		printf(" ");
	printf("Password");
	for(i=0;i<(buffer-(strlen("Password")%2==0?(strlen("Password")):(strlen("Password")-1))-2)/2;i++)
		printf(" ");
	printf("=");
	printf("=");
	for(i=0;i<(buffer-strlen("Email")-2)/2;i++)
		printf(" ");
	printf("Email");
	for(i=0;i<(buffer-(strlen("Email")%2==0?(strlen("Email")):(strlen("Email")-1))-2)/2;i++)
		printf(" ");
	printf("=");
	printf("=");
	for(i=0;i<(buffer-strlen("Character")-2)/2;i++)
		printf(" ");
	printf("Character");
	for(i=0;i<(buffer-(strlen("Character")%2==0?(strlen("Character")):(strlen("Character")-1))-2)/2;i++)
		printf(" ");
	printf("=");		
	printf("\n");
	for(i=0;i<5*buffer;i++)
		printf("=");		
	for(j=0;j<=size;j++)
	{	
		printf("\n");
		for(i=0;i<5*buffer;i++)
			printf("=");
		printf("\n");		
		printf("=");	
		for(i=0;i<(buffer-((numarcifre(j)%2)==0?(numarcifre(j)):(numarcifre(j)))-2)/2;i++)
			printf(" ");
		printf("%d",j);
		for(i=0;i<(buffer-((numarcifre(j)%2)==0?(numarcifre(j)):(numarcifre(j)-1))-2)/2;i++)
			printf(" ");
		printf("=");		
		printf("=");
		for(i=0;i<(buffer-strlen((ThisArray+j)->Username)-2)/2;i++)
			printf(" ");		
		printf((ThisArray+j)->Username);
		for(i=0;i<(buffer-(strlen((ThisArray+j)->Username)%2==0?(strlen((ThisArray+j)->Username)):(strlen((ThisArray+j)->Username)-1))-2)/2;i++)
			printf(" ");
		printf("=");		
		printf("=");
		for(i=0;i<(buffer-strlen((ThisArray+j)->Password)-2)/2;i++)
			printf(" ");
		printf((ThisArray+j)->Password);
		for(i=0;i<(buffer-(strlen((ThisArray+j)->Password)%2==0?(strlen((ThisArray+j)->Password)):(strlen((ThisArray+j)->Password)-1))-2)/2;i++)
			printf(" ");
		printf("=");		
		printf("=");
		for(i=0;i<(buffer-strlen((ThisArray+j)->Email)-2)/2;i++)
			printf(" ");
		printf((ThisArray+j)->Email);
		for(i=0;i<(buffer-(strlen((ThisArray+j)->Email)%2==0?(strlen((ThisArray+j)->Email)):(strlen((ThisArray+j)->Email)-1))-2)/2;i++)
			printf(" ");
		printf("=");		
		printf("=");
		for(i=0;i<(buffer-strlen((ThisArray+j)->Character)-2)/2;i++)
			printf(" ");
		printf((ThisArray+j)->Character);
		for(i=0;i<(buffer-(strlen((ThisArray+j)->Character)%2==0?(strlen((ThisArray+j)->Character)):(strlen((ThisArray+j)->Character)-1))-2)/2;i++)
			printf(" ");
		printf("=");		
		printf("\n");
		for(i=0;i<5*buffer;i++)
			printf("=");
	}	
}
char* getinfo(char * fcontent,int size,FILE *f){
	fgets(fcontent,size,f);
	return strtok(fcontent,"\n");
}
void avoiderror(){
	FILE *f;
	char *ThisFile;
	ThisFile = (char*)malloc(sizeof(char)*(strlen(LoginDirectory)+strlen(errortext)));
	strcpy(ThisFile,LoginDirectory);
	strcat(ThisFile,errortext);
	f=fopen(ThisFile,"r");
	char *fcontent;
	fcontent = (char *)malloc(filesize(ThisFile)*sizeof(char));
	free(ThisFile);
	fclose(f);	
	free(f);
	free(fcontent);	
}
void alege(){
	struct VectPointer * VectPointer;
	VectPointer =(struct VectPointer*)malloc(5*sizeof(struct VectPointer));
	int z=0;	
		(VectPointer+0)->functiedeordonare=&orderaccount;
		(VectPointer+1)->functiedeordonare=&orderbonus;
		(VectPointer+2)->functiedeordonare=&orderspell;
		(VectPointer+3)->functiedeordonare=&orderitem;
		(VectPointer+4)->functiedeordonare=&orderplayer;
	
	avoiderror();
	createdirectory((char*)MainDirectory);
	createdirectory((char*)LoginDirectory);
	createdirectory((char*)BonusDirectory);
	createdirectory((char*)SpellDirectory);
	createdirectory((char*)ItemDirectory);
	createdirectory((char*)PlayerDirectory);
	char x[1],m[1];
	do{ 
		if(strcmp(m,"1")==0){
			printf("What you do like to do?\n");	
			printf("1. New Account\n");
			printf("2. Check Account\n");
			printf("3. List Accounts?\n");
			printf("4. Delete Account!\n");
			printf("5. Delete All Accounts!\n");
			printf("6. Change Password for one account.\n");
			printf("7. Change Email for one account.\n");
			printf("8. Change Character for one account.\n");
			printf("E. Order the list accounts by Email.\n");
			printf("C. Order the list accounts by Character.\n");
			printf("0. Exit from Accounts ?\n");	
			printf("[For choose something you must Introdu '1' (for example) without ''.]\n");
			scanf("%s",&x);
			system("cls");
			if(strcmp(x,"0")==0)
			{	
				strcpy(m,"x");
			}
			else
			if(strcmp(x,"1")==0){	
				Add(1,(char*)LoginDirectory);
				strcpy(m,"1");
			}else
			if(strcmp(x,"2")==0){	
				Check(1,(char*)LoginDirectory);
				strcpy(m,"1");
			}
			else
			if(strcmp(x,"3")==0){			
				listaccounts((char*)LoginDirectory);		
				strcpy(m,"1");
			}
			else
			if(strcmp(x,"4")==0)	
			{
				deletefile((char*)LoginDirectory);
				strcpy(m,"1");
			}
			else	
			if(strcmp(x,"5")==0)	
			{
				deleteall((char*)LoginDirectory);
				strcpy(m,"1");
			}
			else	
			if(strcmp(x,"6")==0)	
			{
				change(1,1,(char*)LoginDirectory);
				strcpy(m,"1");
			}
			else	
			if(strcmp(x,"7")==0)	
			{
				change(1,2,(char*)LoginDirectory);
				strcpy(m,"1");
			}
			else	
			if(strcmp(x,"8")==0)	
			{
				change(1,3,(char*)LoginDirectory);
				strcpy(m,"1");
			}
			else	
			if(strcmp(x,"E")==0 || strcmp(x,"e")==0)	
			{
				(VectPointer+0)->functiedeordonare((char*)"Email");
				//orderaccount((char*)"Email");
				strcpy(m,"1");
			}
			else	
			if(strcmp(x,"C")==0 || strcmp(x,"c")==0)	
			{
				(VectPointer+0)->functiedeordonare((char*)"Character");
				//orderaccount((char*)"Character");
				strcpy(m,"1");
			}
			else
				strcpy(m,"1");
		}
		else
		if(strcmp(m,"2")==0){
			printf("What you do like to do?\n");	
			printf("1. New Bonus?\n");
			printf("2. Check ?\n");
			printf("3. List Bonuses?\n");
			printf("4. Delete Bonus!\n");
			printf("5. Delete All Bonuses!\n");
			printf("6. Change Name's Bonus\n");
			printf("7. Change TypeBonus's Bonus\n");
			printf("8. Change Value's Bonus\n");
			printf("9. Change if the value's Bonus is percent\n");
			printf("N. Order by Name.\n");
			printf("T. Order by TypeBonus.\n");
			printf("0. Exit from Bonus ?\n");	
			printf("[For choose something you must Introduce '1' (for example) without ''.]\n");
			scanf("%s",&x);
			system("cls");
			if(strcmp(x,"0")==0)
			{				
				strcpy(m,"x");
			}
			else
			if(strcmp(x,"1")==0)
			{	
				Add(2,(char*)BonusDirectory);
				strcpy(m,"2");
			}
			else
			if(strcmp(x,"2")==0)
			{	
				Check(2,(char*)BonusDirectory);
				strcpy(m,"2");
			}
			else
			if(strcmp(x,"3")==0)
			{	
				listbonuses((char*)BonusDirectory);
				strcpy(m,"2");
			}
			else
			if(strcmp(x,"4")==0)
			{	
				deletefile((char*)BonusDirectory);
				strcpy(m,"2");
			}
			else
			if(strcmp(x,"5")==0)
			{	
				deleteall((char*)BonusDirectory);
				strcpy(m,"2");
			}
			else
			if(strcmp(x,"6")==0)
			{	
				change(2,1,(char*)BonusDirectory);
				strcpy(m,"2");
			}
			else
			if(strcmp(x,"7")==0)
			{	
				change(2,2,(char*)BonusDirectory);
				strcpy(m,"2");
			}
			else
			if(strcmp(x,"8")==0)
			{	
				change(2,3,(char*)BonusDirectory);
				strcpy(m,"2");
			}
			else
			if(strcmp(x,"9")==0)
			{	
				change(2,4,(char*)BonusDirectory);
				strcpy(m,"2");
			}
			else
			if(strcmp(x,"N")==0 || strcmp(x,"n")==0)
			{	
				(VectPointer+1)->functiedeordonare((char*)"Name");
			//	orderbonus((char*)"Name");
				strcpy(m,"2");
			}
			else
			if(strcmp(x,"T")==0 || strcmp(x,"t")==0)
			{	
				(VectPointer+1)->functiedeordonare((char*)"TypeBonus");
			//	orderbonus((char*)"TypeBonus");
				strcpy(m,"2");
			}
			else
				strcpy(m,"2");
		}
		else
		if(strcmp(m,"3")==0){
			printf("What you do like to do?\n");	
			printf("1. New Spell?\n");
			printf("2. Check ?\n");
			printf("3. List Spells?\n");
			printf("4. Delete Spell!\n");
			printf("5. Delete All Spells!\n");
			printf("6. Change Name's Spell\n");
			printf("7. Change TypeBonus's Spell\n");
			printf("8. Change Cooldown's Spell\n");
			printf("9. Change the Bonus's Spell\n");
			printf("N. Order by Name.\n");
			printf("T. Order by TypeSpell.\n");
			printf("0. Exit from Spell ?\n");	
			printf("[For choose something you must Introduce '1' (for example) without ''.]\n");
			scanf("%s",&x);
			system("cls");
			if(strcmp(x,"0")==0)
			{				
				strcpy(m,"x");
			}
			else
			if(strcmp(x,"1")==0)
			{			
				Add(3,(char*)SpellDirectory);
				strcpy(m,"3");
			}
			else
			if(strcmp(x,"2")==0)
			{			
				Check(3,(char*)SpellDirectory);
				strcpy(m,"3");
			}
			else
			if(strcmp(x,"3")==0)
			{		
				listspells((char*)SpellDirectory);
				strcpy(m,"3");
			}
			else
			if(strcmp(x,"4")==0)
			{		
				deletefile((char*)SpellDirectory);
				strcpy(m,"3");
			}
			else
			if(strcmp(x,"5")==0)
			{		
				deleteall((char*)SpellDirectory);
				strcpy(m,"3");
			}
			else
			if(strcmp(x,"6")==0)
			{			
				change(3,1,(char*)SpellDirectory);
				strcpy(m,"3");
			}
			else
			if(strcmp(x,"7")==0)
			{				
				change(3,2,(char*)SpellDirectory);
				strcpy(m,"3");
			}
			else
			if(strcmp(x,"8")==0)
			{				
				change(3,3,(char*)SpellDirectory);
				strcpy(m,"3");
			}
			else
			if(strcmp(x,"9")==0)
			{				
				change(3,4,(char*)SpellDirectory);
				strcpy(m,"3");
			}
			else
			if(strcmp(x,"T")==0 || strcmp(x,"t")==0)
			{	
				(VectPointer+2)->functiedeordonare((char*)"TypeSpell");
			//	orderspell((char*)"TypeSpell");
				strcpy(m,"3");
			}
			else
			if(strcmp(x,"N")==0 || strcmp(x,"n")==0)
			{		
				(VectPointer+2)->functiedeordonare((char*)"Name");
			//	orderspell((char*)"Name");		
				strcpy(m,"3");
			}
			else
			strcpy(m,"3");
		}
		else
		if(strcmp(m,"4")==0){
			printf("What you do like to do?\n");	
			printf("1. New Item?\n");					
			printf("2. Delete Item!\n");
			printf("3. Delete All Items!\n");
			printf("4. Change Name's Item\n");
			printf("5. Change TypeBonus's Item\n");
			printf("6. Change HealthPoint's Item\n");
			printf("7. Change Weight's Item\n");
			printf("8. Change Sharp's Item\n");
			printf("9. Change Bonuses's Item\n");
			printf("C. Check ?\n");	
			printf("L. List Items?\n");
			printf("N. Order by Name.\n");
			printf("T. Order by Type.\n");
			printf("0. Exit from Items ?\n");	
			printf("[For choose something you must Introduce '1' (for example) without ''.]\n");
			scanf("%s",&x);
			system("cls");
			if(strcmp(x,"0")==0)
			{				
				strcpy(m,"x");
			}
			else
			if(strcmp(x,"1")==0)
			{			
				Add(4,(char*)ItemDirectory);
				strcpy(m,"4");
			}
			else
			if(strcmp(x,"C")==0 || strcmp(x,"c")==0)
			{			
				Check(4,(char*)ItemDirectory);
				strcpy(m,"4");
			}
			else
			if(strcmp(x,"l")==0 || strcmp(x,"L")==0)
			{		
				listitems((char*)ItemDirectory);
				strcpy(m,"4");
			}
			else
			if(strcmp(x,"2")==0)
			{		
				deletefile((char*)ItemDirectory);
				strcpy(m,"4");
			}
			else
			if(strcmp(x,"3")==0)
			{		
				deleteall((char*)ItemDirectory);
				strcpy(m,"4");
			}
			else
			if(strcmp(x,"4")==0)
			{			
				change(4,1,(char*)ItemDirectory);
				strcpy(m,"4");
			}
			else
			if(strcmp(x,"5")==0)
			{		
				change(4,2,(char*)ItemDirectory);		
				strcpy(m,"4");
			}
			else
			if(strcmp(x,"6")==0)
			{		
				change(4,3,(char*)ItemDirectory);		
				strcpy(m,"4");
			}
			else
			if(strcmp(x,"7")==0)
			{		
				change(4,4,(char*)ItemDirectory);
				strcpy(m,"4");
			}
			else
			if(strcmp(x,"8")==0)
			{	
				change(4,5,(char*)ItemDirectory);
				strcpy(m,"4");
			}
			else
			if(strcmp(x,"9")==0)
			{	
				change(4,6,(char*)ItemDirectory);
				strcpy(m,"4");
			}
			else
			if(strcmp(x,"T")==0 || strcmp(x,"t")==0)
			{			
				(VectPointer+3)->functiedeordonare((char*)"TypeItem");		
			//	orderitem((char*)"TypeItem");
				strcpy(m,"4");
			}
			else
			if(strcmp(x,"N")==0 || strcmp(x,"n")==0)				
			{	
				(VectPointer+3)->functiedeordonare((char*)"Name");
			//	orderitem((char*)"Name");			
				strcpy(m,"4");
			}
			else
			strcpy(m,"4");			
		}
		else
		if(strcmp(m,"5")==0){			
			printf("What you do like to do?\n");	
			printf("1. New Player?\n");			
			printf("2. Delete Player!\n");
			printf("3. Delete All Players!\n");
			printf("4. Change Account's Players\n");
			printf("5. Change HP's Player\n");
			printf("6. Change Mana's Player\n");
			printf("7. Change Defense's Player\n");
			printf("8. Change MovementSpeed's Player\n");						
			printf("C. Check ?\n");				
			printf("L. List Players?\n");
			printf("A. Order by Account.\n");
			printf("0. Exit from Players ?\n");	
			printf("[For choose something you must Introduce '1' (for example) without ''.]\n");
			scanf("%s",&x);
			system("cls");
			if(strcmp(x,"0")==0){				
				strcpy(m,"x");
			}else
			if(strcmp(x,"1")==0){			
				Add(5,(char*)PlayerDirectory);
				strcpy(m,"5");
			}else
			if(strcmp(x,"C")==0 || strcmp(x,"c")==0){			
				Check(5,(char*)PlayerDirectory);
				strcpy(m,"5");
			}else
			if(strcmp(x,"l")==0 || strcmp(x,"L")==0){		
				listplayers((char*)PlayerDirectory);
				strcpy(m,"5");
			}else
			if(strcmp(x,"2")==0){		
				deletefile((char*)PlayerDirectory);
				strcpy(m,"5");
			}else
			if(strcmp(x,"3")==0){		
				deleteall((char*)PlayerDirectory);
				strcpy(m,"5");
			}else
			if(strcmp(x,"4")==0){				
				change(5,1,(char*)PlayerDirectory);
				strcpy(m,"5");
			}else
			if(strcmp(x,"5")==0){				
				change(5,2,(char*)PlayerDirectory);
				strcpy(m,"5");
			}else
			if(strcmp(x,"6")==0){				
				change(5,3,(char*)PlayerDirectory);
				strcpy(m,"5");
			}else
			if(strcmp(x,"7")==0){				
				change(5,4,(char*)PlayerDirectory);
				strcpy(m,"5");
			}else
			if(strcmp(x,"8")==0){				
				change(5,5,(char*)PlayerDirectory);
				strcpy(m,"5");
			}else
			if(strcmp(x,"A")==0 || strcmp(x,"a")==0){	
				(VectPointer+4)->functiedeordonare((char*)"Account");
			//	orderplayer((char*)"Account");
				strcpy(m,"5");
			}else						
			strcpy(m,"5");
		}		
		else
		{
			printf("Choose your table : \n");
			printf("1. Accounts. \n");
			printf("2. Bonus \n");
			printf("3. Spells \n");
			printf("4. Items \n");
			printf("5. Players \n");
			printf("0. Exit program \n");
			printf("[For choose something you must Introduce '1' (for example) without ''.]\n");
			scanf("%s",&m);
		}
		system("cls");
	}while(strcmp(m,"0")!=0);
	free(VectPointer);
}
void deletefile(char *Directory){
	printf("What would you like you delete?\n");
	char aux[50];
	scanf("%s",&aux);
	char *ThisFile;
	ThisFile=(char*)malloc(sizeof(char)*(strlen(Directory)+strlen(aux)));
	strcpy(ThisFile,Directory);
	strcat(ThisFile,aux);
	FILE *f;
	f=fopen(ThisFile,"r");
	if(f==NULL){
		printf("Doesn't exist!\n");
		fclose(f);
	} else
	{
		fclose(f);
		remove(ThisFile); // stergefisier
		printf("Deleted!\n");		
	}	
	free(ThisFile);
	printf("\n");system("pause");
}
void deleteall(char * Directory){
	DIR *pDIR;
    struct dirent *entry;
	if( pDIR=opendir(Directory) ){
        while(entry = readdir(pDIR)){
			if(strcmp(entry->d_name, "..") != 0 && (strcmp(entry->d_name, ".") != 0)){				
				char *ThisFile;
				ThisFile = (char*)malloc(sizeof(char)*(strlen(Directory)+strlen(entry->d_name)));
				strcpy(ThisFile,Directory);
				strcat(ThisFile,entry->d_name);					
				remove(ThisFile);
				free(ThisFile);
			}
        }
        closedir(pDIR);
    }
	printf("Deleted!\n");
	printf("\n");system("pause");
}
void change(int where,int what,char*Directory){
	printf("Introduce where and what to change!\n");
	printf("");
	char u[50];
	scanf("%s",&u);		
	FILE *f;
	char *ThisFile;
	ThisFile = (char*)malloc(sizeof(char)*(strlen(Directory)+strlen(u)));
	strcpy(ThisFile,Directory);
	strcat(ThisFile,u);
	f=fopen(ThisFile,"r");	
	if(f!=NULL){
		if(where==1){
			if(what==1){
				char p[50];
				scanf("%s",&p);	
				char *fcontent;
				fcontent = (char *)malloc(filesize(ThisFile)*sizeof(char));			
				char *aux,*Email,*Character;
				getinfo(fcontent,(1+filesize(ThisFile)),f);		
				aux=getinfo(fcontent,(1+filesize(ThisFile)),f);
				Email=(char*)malloc(sizeof(aux));
				strcpy(Email,aux);		
				aux=getinfo(fcontent,(1+filesize(ThisFile)),f);
				Character=(char*)malloc(sizeof(aux));
				strcpy(Character,aux);		
				fclose(f);	
				free(f);
				free(fcontent);	
				f=fopen(ThisFile,"w");
				fprintf(f,p);
				fprintf(f,"\n");
				fprintf(f,Email);
				fprintf(f,"\n");
				fprintf(f,Character);	
				fclose(f);
				printf("\nChanged!\n");				
			}
			else
			if(what==2){
				char e[50];
				scanf("%s",&e);	
				char *fcontent;
				fcontent = (char *)malloc(filesize(ThisFile)*sizeof(char));			
				char *aux,*Password,*Character;
				aux=getinfo(fcontent,(1+filesize(ThisFile)),f);
				Password=(char*)malloc(sizeof(aux));
				strcpy(Password,aux);
				getinfo(fcontent,(1+filesize(ThisFile)),f);		
				aux=getinfo(fcontent,(1+filesize(ThisFile)),f);
				Character=(char*)malloc(sizeof(aux));
				strcpy(Character,aux);
				fclose(f);	
				free(f);
				free(fcontent);	
				f=fopen(ThisFile,"w");
				fprintf(f,Password);
				fprintf(f,"\n");
				fprintf(f,e);
				fprintf(f,"\n");
				fprintf(f,Character);
				fclose(f);
				printf("\nChanged!\n");
			}
			else
			if(what==3){
				char c[50];
				scanf("%s",&c);	
				FILE *f2;
				char*pathfile;
				pathfile = (char*)malloc(sizeof(char)*(strlen(PlayerDirectory)+strlen(c)));
				strcpy(pathfile,PlayerDirectory);
				strcat(pathfile,c);
				f2=fopen(pathfile,"r");
				if(f2!=NULL){
					char *fcontent;
					fcontent = (char *)malloc(filesize(ThisFile)*sizeof(char));			
					char *aux,*Password,*Email;
					aux=getinfo(fcontent,(1+filesize(ThisFile)),f);
					Password=(char*)malloc(sizeof(aux));
					strcpy(Password,aux);				
					aux=getinfo(fcontent,(1+filesize(ThisFile)),f);		
					Email=(char*)malloc(sizeof(aux));
					strcpy(Email,aux);
					getinfo(fcontent,(1+filesize(ThisFile)),f);				
					fclose(f);	
					free(f);
					free(fcontent);	
					f=fopen(ThisFile,"w");
					fprintf(f,Password);
					fprintf(f,"\n");
					fprintf(f,Email);
					fprintf(f,"\n");
					fprintf(f,c);
					fclose(f);
					printf("\nChanged!\n");
				} else
				{
					printf("Doesn't exist!");
				}
				fclose(f2);
				free(f2);
				free(pathfile);
			}				
		}
		else
		if(where==2){
			if(what==1){				
				char n[50];
				scanf("%s",&n);	
				char *fcontent;
				fcontent = (char *)malloc(filesize(ThisFile)*sizeof(char));			
				int TypeBonus,value,IsPercent;
				getinfo(fcontent,(1+filesize(ThisFile)),f);	
				free(fcontent);
				
				fscanf(f,"%d",&TypeBonus);
				fscanf(f,"%d",&value);
				fscanf(f,"%d",&IsPercent);
				fclose(f);	
				free(f);				
				f=fopen(ThisFile,"w");
				fprintf(f,n);
				fprintf(f,"\n");
				fprintf(f,"%d",TypeBonus);
				fprintf(f,"\n");
				fprintf(f,"%d",value);
				fprintf(f,"\n");
				fprintf(f,"%d",IsPercent);
				printf("\nName changed!\n");
				fclose(f);
			}
			else
			if(what==2){
				char n[50];
				int TypeBonus,value,IsPercent;
				int aux;
				aux=citestenumber();if(aux!=-1){
					//scanf("%d",&TypeBonus);	
					TypeBonus=aux;
					char *fcontent;
					fcontent = (char *)malloc(filesize(ThisFile)*sizeof(char));				
					strcpy(n,getinfo(fcontent,(1+filesize(ThisFile)),f));	
					free(fcontent);		
					int *something;
					something=(int *)malloc(sizeof(int));
					fscanf(f,"%d",&something);
					free(something);
					fscanf(f,"%d",&value);
					fscanf(f,"%d",&IsPercent);
					fclose(f);	
					free(f);				
					f=fopen(ThisFile,"w");
					fprintf(f,n);
					fprintf(f,"\n");
					fprintf(f,"%d",TypeBonus);
					fprintf(f,"\n");
					fprintf(f,"%d",value);
					fprintf(f,"\n");
					fprintf(f,"%d",IsPercent);	
					printf("\nChanged!\n");	
				} else
				{
					printf("\nData Wrong\n");
				}
							
			}
			else
			if(what==3){
				char n[50];
				int TypeBonus,value,IsPercent;
				int aux;
				aux=citestenumber();if(aux!=-1){
					value=aux;					
					char *fcontent;
					fcontent = (char *)malloc(filesize(ThisFile)*sizeof(char));				
					strcpy(n,getinfo(fcontent,(1+filesize(ThisFile)),f));	
					free(fcontent);		
					int *something;				
					fscanf(f,"%d",&TypeBonus);			
					something=(int *)malloc(sizeof(int));
					fscanf(f,"%d",&something);
					free(something);
					fscanf(f,"%d",&IsPercent);
					fclose(f);	
					free(f);				
					f=fopen(ThisFile,"w");
					fprintf(f,n);
					fprintf(f,"\n");
					fprintf(f,"%d",TypeBonus);
					fprintf(f,"\n");
					fprintf(f,"%d",value);
					fprintf(f,"\n");
					fprintf(f,"%d",IsPercent);		
					printf("\nChanged!\n");	
				} else
				{
					printf("\nData Wrong\n");
				}				
			}
			else
			if(what==4){
				char n[50];
				int TypeBonus,value,IsPercent;	
				int aux;
				aux=citestenumber();if(aux!=-1){
					IsPercent=aux;
					if(IsPercent==0 || IsPercent==1){
					char *fcontent;
					fcontent = (char *)malloc(filesize(ThisFile)*sizeof(char));				
					strcpy(n,getinfo(fcontent,(1+filesize(ThisFile)),f));	
					free(fcontent);		
					int *something;				
					fscanf(f,"%d",&TypeBonus);				
					fscanf(f,"%d",&value);
					something=(int *)malloc(sizeof(int));
					fscanf(f,"%d",&something);
					free(something);
					fclose(f);	
					free(f);				
					f=fopen(ThisFile,"w");
					fprintf(f,n);
					fprintf(f,"\n");
					fprintf(f,"%d",TypeBonus);
					fprintf(f,"\n");
					fprintf(f,"%d",value);
					fprintf(f,"\n");
					fprintf(f,"%d",IsPercent);
					printf("\nIsPercent changed!\n");
					}
					else
					{
						printf("Wrong value introduced![Just 0 or 1]");
					}
				} else
				{
					printf("\nData Wrong\n");
				}
			}			
		}
		else
		if(where==3){
			int ok=1;
			struct Spell *ThisSpell;
			ThisSpell=(struct Spell *)malloc(sizeof(struct Spell));
			fscanf(f,"%s %d %d %s",
					&(ThisSpell->Name),
					&(ThisSpell->TypeSpell),
					&(ThisSpell->Cooldown),
					&(ThisSpell->Bonuses)
				);
			fclose(f);
			if(what==1){ // Name
				char n[50];				
				scanf("%s",&n);								
				strcpy(ThisSpell->Name,n);
			}else
			if(what==2){ //TypeSpell
				int aux;
				aux=citestenumber();if(aux!=-1){
					ThisSpell->TypeSpell=aux;
				} else
				{
					ok=0;
					printf("\nData Wrong\n");
				}
				
			}else
			if(what==3){ //Cooldown
				int aux;
				aux=citestenumber();if(aux!=-1){				
				ThisSpell->Cooldown=aux;
				} else
				{
					ok=0;
					printf("\nData Wrong\n");
				}
			}else
			if(what==4){ // Bonuses
				char n[50];				
				scanf("%s",&n);								
				strcpy(ThisSpell->Bonuses,n);
			}
			if(ok==1){
			f=fopen(ThisFile,"w");
			fprintf(f,"%s\n%d\n%d\n%s",
					(ThisSpell->Name),
					(ThisSpell->TypeSpell),
					(ThisSpell->Cooldown),
					(ThisSpell->Bonuses)
				);	
			printf("\nChanged!\n");	
			}				
			free(ThisSpell);					
		}
		else
		if(where==4){	
			int ok=1;
			struct Item *ThisItem;
			ThisItem=(struct Item *)malloc(sizeof(struct Item));
			fscanf(f,"%s %d %d %d %d %s",
					&(ThisItem->Name),
					&(ThisItem->TypeItem),
					&(ThisItem->HealthPoint),
					&(ThisItem->Weight),
					&(ThisItem->Sharp),
					&(ThisItem->Bonuses)
				);
			fclose(f);
			if(what==1){ // Name
				char n[50];				
				scanf("%s",&n);								
				strcpy(ThisItem->Name,n);
			}else
			if(what==2){ //TypeItem
				int aux;
				aux=citestenumber();if(aux!=-1){				
				ThisItem->TypeItem=aux;
				} else
				{
					ok=0;
					printf("\nData Wrong\n");
				}
			}else
			if(what==3){ // HealthPoint
				int aux;
				aux=citestenumber();if(aux!=-1){				
				ThisItem->HealthPoint=aux;
				} else
				{
					ok=0;
					printf("\nData Wrong\n");
				}
			}else
			if(what==4){ // Weight
				int aux;
				aux=citestenumber();if(aux!=-1){				
				ThisItem->Weight=aux;
				} else
				{
					ok=0;
					printf("\nData Wrong\n");
				}
			}else
			if(what==5){ // Sharp
				int aux;
				aux=citestenumber();if(aux!=-1){				
				ThisItem->Sharp=aux;
				} else
				{
					ok=0;
					printf("\nData Wrong\n");
				}
			}else
			if(what==6){ // Bonuses
				char n[50];				
				scanf("%s",&n);								
				strcpy(ThisItem->Bonuses,n);
			}
			if(ok==1){
			f=fopen(ThisFile,"w");
			fprintf(f,"%s\n%d\n%d\n%d\n%d\n%s",
					(ThisItem->Name),
					(ThisItem->TypeItem),
					(ThisItem->HealthPoint),
					(ThisItem->Weight),
					(ThisItem->Sharp),
					(ThisItem->Bonuses)
				);		
			printf("\nChanged!\n");
			}				
			free(ThisItem);	
			
		}
		else
		if(where==5){			
			struct Player *ThisPlayer;
			ThisPlayer=(struct Player *)malloc(sizeof(struct Player));
			fscanf(f,"%s %d %d %d %d %d %d %d %d %d",
					//&(ThisPlayer->Username),
					&(ThisPlayer->Account),					
					&(ThisPlayer->Level),
					&(ThisPlayer->HP),
					&(ThisPlayer->Mana),
					&(ThisPlayer->Vitality),
					&(ThisPlayer->Strength),
					&(ThisPlayer->Agility),
					&(ThisPlayer->Intelligence),
					&(ThisPlayer->Defense),
					&(ThisPlayer->MovementSpeed)
				);
			fclose(f);
			if(what==1){ // Account
				char n[50];				
				scanf("%s",&n);								
				strcpy(ThisPlayer->Account,n);					
				FILE *f2;
				char*pathfile;
				pathfile = (char*)malloc(sizeof(char)*(strlen(LoginDirectory)+strlen(n)));
				strcpy(pathfile,LoginDirectory);
				strcat(pathfile,n);
				f2=fopen(pathfile,"r");
				if(f2!=NULL){							
					fclose(f);	
					free(f);
					f=fopen(ThisFile,"w");					
					fprintf(f,"%s %d %d %d %d %d %d %d %d %d %s %s",
						//&(ThisPlayer->Username),
						(ThisPlayer->Account),					
						(ThisPlayer->Level),
						(ThisPlayer->HP),
						(ThisPlayer->Mana),
						(ThisPlayer->Vitality),
						(ThisPlayer->Strength),
						(ThisPlayer->Agility),
						(ThisPlayer->Intelligence),
						(ThisPlayer->Defense),
						(ThisPlayer->MovementSpeed),
						"NULL",
						"NULL"
					);						
					printf("\nChanged!\n");
				} else
				{
					printf("Doesn't exist!");
				}
				fclose(f2);
				free(f2);
				free(pathfile);
			}else
			{
				if(what==2){ //HP
					int x;
					scanf("%d",&x);
					ThisPlayer->HP=x;
					printf("\nChanged!\n");
				}else
				if(what==3){ // Mana
					int x;
					scanf("%d",&x);
					ThisPlayer->Mana=x;
					printf("\nChanged!\n");
				}else
				if(what==4){ // Defense
					int x;
					scanf("%d",&x);
					ThisPlayer->Defense=x;
					printf("\nChanged!\n");
				}else
				if(what==5){ // MovementSpeed
					int x;
					scanf("%d",&x);
					ThisPlayer->MovementSpeed=x;
					printf("\nChanged!\n");
				}
				f=fopen(ThisFile,"w");			
				fprintf(f,"%s %d %d %d %d %d %d %d %d %d %s %s",
						//&(ThisPlayer->Username),
						(ThisPlayer->Account),					
						(ThisPlayer->Level),
						(ThisPlayer->HP),
						(ThisPlayer->Mana),
						(ThisPlayer->Vitality),
						(ThisPlayer->Strength),
						(ThisPlayer->Agility),
						(ThisPlayer->Intelligence),
						(ThisPlayer->Defense),
						(ThisPlayer->MovementSpeed),
						"NULL",
						"NULL"
					);	
			}				
			free(ThisPlayer);				
		}		
	}
	else
	{
		printf("\nDoesn't exist!\n");
	}
	free(ThisFile);
	printf("\n");system("pause");	
}
void Add(int what,char* Directory){
	if(what==1){
		printf("Introduce Username,password and email for account!\n");
	}else
	if(what==2){
		printf("Introdu ID,nume,tip bonus,valoarea,este in procente(1/0)!\n");
	}else
	if(what==3){
		printf("Introduce ID, Name, TypeSpell,Cooldown,and some bonuses(if you want)!\n");
	}else
	if(what==4){
		printf("Introduce ID, Name, Type,HealthPoint,Weight,Sharp,and some bonuses(if you want)!\n");
	}else
	if(what==5){
		printf("Introduce Username,Level,HP,Mana,Vitality,Strength,Agility,Intelligence,Defense,MovementSpeed(values)\n");
	}
	FILE *f;
	char where[50];
	scanf("%s",&where);
	char *paux;
	paux=(char*)malloc((strlen(Directory)+strlen(where))*sizeof(char));
	strcpy(paux,Directory);
	strcat(paux,where);
	f=fopen(paux,"r");
	int ok=1;
	if(f==NULL){
		fclose(f);		
		if(what==1){
			f=fopen(paux,"w");
			char p[50],e[50];
			scanf("%s %s",&p,&e);
			fprintf(f,p);
			fprintf(f,"\n");
			fprintf(f,e);
			fprintf(f,"\n");
			fprintf(f,"NULL");		
		}
		else	if(what==2){			
			struct Bonus *ThisBonus;
			ThisBonus=(struct Bonus *)malloc(sizeof(struct Bonus));
			scanf("%s",&(ThisBonus->Name));
			int aux;
			aux=citestenumber();if(aux==-1){
				printf("Data wrong!\n");
				ok=0;
			} else
			{
				(ThisBonus->TypeBonus)=aux;
			}
			aux=citestenumber();if(aux==-1){
				ok=0;
				printf("Data wrong!\n");
			} else
			{
				(ThisBonus->value)=aux;
			}
			aux=citestenumber();if(aux==-1){
				ok=0;
				printf("Data wrong!\n");
			} else
			{	
				if(aux==0 || aux==1)
				(ThisBonus->IsPercent)=aux;
				else
				{
					ok=0;
				printf("Data wrong!\n");
				}
			}
			if(ok==1){			
			f=fopen(paux,"w");
			free(paux);				
			fprintf(f,"%s",(ThisBonus->Name));				
			fprintf(f,"\n");				
			fprintf(f,"%d",(ThisBonus->TypeBonus));				
			fprintf(f,"\n");			
			fprintf(f,"%d",(ThisBonus->value));
			fprintf(f,"\n");
			fprintf(f,"%d",(ThisBonus->IsPercent));	
			
			fclose(f);
			}
			free(ThisBonus);
		}
		else	if(what==3){
			struct Spell *ThisSpell;
			ThisSpell=(struct Spell *)malloc(sizeof(struct Spell));
			int aux;
			scanf("%s",&(ThisSpell->Name));
			aux=citestenumber();if(aux==-1){
				ok=0;
				printf("Data wrong!\n");
			}else
			{
				ThisSpell->TypeSpell=aux;
			}
			aux=citestenumber();if(aux==-1){
				ok=0;
				printf("Data wrong!\n");
			}else
			{				
				ThisSpell->Cooldown=aux;
			}
			scanf("%s",&(ThisSpell->Bonuses));//struct Bonus *Bonuses;
			if(ok==1){
			f=fopen(paux,"w");
			fprintf(f,"%s\n%d\n%d\n%s",
				ThisSpell->Name,
				(ThisSpell->TypeSpell),
				(ThisSpell->Cooldown),
				(ThisSpell->Bonuses)			//struct Bonus *Bonuses;	
				);
			fclose(f);
			printf("Saved");
			}			
			free(paux);				
			free(ThisSpell);
		}	
		else	if(what==4){
			fclose(f);
			struct Item *ThisItem;
			ThisItem=(struct Item *)malloc(sizeof(struct Item));			
			scanf("%s",&(ThisItem->Name));
			int aux;
			aux=citestenumber();
			if(aux==-1){
				ok=0;
				printf("Data wrong\n");
			}else
			{
				//printf("este %d",typeitemEND);
				if(aux>=0 && aux<typeitemEND){
					//printf("da");
					(ThisItem->TypeItem)=aux;
				}
				else
				{
					ok=0;
				printf("Data wrong\n");
				}
			}
			aux=citestenumber();
			if(aux==-1){
				ok=0;
				printf("Data wrong\n");
			}else{
				(ThisItem->HealthPoint)=aux;
			}
			aux=citestenumber();
			if(aux==-1){
				ok=0;
				printf("Data wrong\n");
			}else{
				(ThisItem->Weight)=aux;
			}
			aux=citestenumber();
			if(aux==-1){
				ok=0;
				printf("Data wrong\n");
			}else
			{
				(ThisItem->Sharp)=aux;
			}			
			scanf("%s",&(ThisItem->Bonuses));	//struct Bonus *Bonuses;
			if(ok==1){
			f=fopen(paux,"w");
			fprintf(f,"%s\n%d\n%d\n%d\n%d\n%s",
				ThisItem->Name,
				(ThisItem->TypeItem),
				(ThisItem->HealthPoint),
				(ThisItem->Weight),
				(ThisItem->Sharp),
				(ThisItem->Bonuses)		//struct Bonus *Bonuses;
				);				
			fclose(f);
			}
			free(paux);
			free(ThisItem);
		}
		else	if(what==5){
			fclose(f);
			struct Player *ThisPlayer;
			ThisPlayer=(struct Player *)malloc(sizeof(struct Player));			
			int aux;
			aux=citestenumber();if(aux==-1){
				ok=0;
				printf("Data wrong\n");
			}else{
				(ThisPlayer->Level)=aux;
			}
			aux=citestenumber();if(aux==-1){
				ok=0;
				printf("Data wrong\n");
			}else{
				(ThisPlayer->HP)=aux;
			}
			aux=citestenumber();if(aux==-1){
				ok=0;
				printf("Data wrong\n");
			}else{
				(ThisPlayer->Mana)=aux;
			}
			aux=citestenumber();if(aux==-1){
				ok=0;
				printf("Data wrong\n");
			}else{
				(ThisPlayer->Vitality)=aux;
			}
			aux=citestenumber();if(aux==-1){
				ok=0;
				printf("Data wrong\n");
			}else{
				(ThisPlayer->Strength)=aux;
			}
			aux=citestenumber();if(aux==-1){
				ok=0;
				printf("Data wrong\n");
			}else{
				(ThisPlayer->Agility)=aux;
			}
			aux=citestenumber();if(aux==-1){
				ok=0;
				printf("Data wrong\n");
			}else{
				(ThisPlayer->Intelligence)=aux;
			}
			aux=citestenumber();if(aux==-1){
				ok=0;
				printf("Data wrong\n");
			}else{
				(ThisPlayer->Defense)=aux;
			}
			aux=citestenumber();if(aux==-1){
				ok=0;
				printf("Data wrong\n");
			}else{				
				(ThisPlayer->MovementSpeed)=aux;
			}
			if(ok==1){
				f=fopen(paux,"w");
				fprintf(f,"%s\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%s\n%s",
						//(ThisPlayer->Account),
						"NULL",
						(ThisPlayer->Level),
						(ThisPlayer->HP),
						(ThisPlayer->Mana),
						(ThisPlayer->Vitality),
						(ThisPlayer->Strength),
						(ThisPlayer->Agility),
						(ThisPlayer->Intelligence),
						(ThisPlayer->Defense),
						(ThisPlayer->MovementSpeed),
						"NULL",		//	struct Bonus *Bonuses;
						"NULL"		//	struct Bonus *Bonuses;
						);
				fclose(f);
				}
			free(paux);
			free(ThisPlayer);
		}	
		if(ok==1)
		printf("Saved\n");
		fclose(f);
	}
	else
	{
		free(paux);
		fclose(f);
		printf("Already exist\n");
	}
	printf("\n");system("pause");	
}
void Check(int where,char*Directory){
	if(where==1){
		printf("Introduce Name's account for get information!\n");
	}
	else
	if(where==2){
		printf("Introduce ID's Bonus for get information\n");
	}
	else
	if(where==3){
		printf("Introduce ID's Spell for get information!\n");
	}
	else
	if(where==4){
		printf("Introduce ID's Item for get information!\n");
	}
	else
	if(where==5){
		printf("Introduce Username's Player for get information!\n");
	}
	FILE *f;
	char ID[50];	
	scanf("%s",&ID);	
	char *paux;
	paux=(char*)malloc((strlen(Directory)+strlen(ID))*sizeof(char));
	strcpy(paux,Directory);
	strcat(paux,ID);			
	f=fopen(paux,"r");
	free(paux);
	if(f==NULL){
		fclose(f);
		printf("Doesn't exist!\n");
	}
	else
	{
		if(where==1){
			struct Account *ThisAccount;
			ThisAccount=(struct Account*)malloc(sizeof(struct Account));		
			printf("Username : %s\n",ID);		
			fscanf(f,"%s",&(ThisAccount->Password));
			printf("Password : %s\n",ThisAccount->Password);		
			fscanf(f,"%s",&(ThisAccount->Email));		
			printf("Email : %s\n",ThisAccount->Email);		
			fscanf(f,"%s",&(ThisAccount->Character));
			printf("Character : %s\n",ThisAccount->Character);	
			free(ThisAccount);
		}
		else
		if(where==2){
			struct Bonus *ThisBonus;
			ThisBonus=(struct Bonus*)malloc(sizeof(struct Bonus));
			printf("ID bonus : %s\n",ID);
			int *aux;
			aux=(int*)malloc(sizeof(int));
			fscanf(f,"%s",&(ThisBonus->Name));
			printf("Numele bonusului : %s\n",ThisBonus->Name);
			fscanf(f,"%d",&aux);
			ThisBonus->TypeBonus=(unsigned int)aux;
			printf("Tipul bonusului : %d\n",ThisBonus->TypeBonus);
			fscanf(f,"%d",&aux);
			ThisBonus->value=(unsigned int)aux;
			printf("Valoarea bonusului : %d\n",ThisBonus->value);
			fscanf(f,"%d",&aux);
			ThisBonus->IsPercent=(unsigned int)aux;
			printf("Este in procente?: %s\n",(ThisBonus->IsPercent)==0?("nu"):("da"));
			free(ThisBonus);			
		}
		else
		if(where==3){
			struct Spell *ThisSpell;
			ThisSpell=(struct Spell *)malloc(sizeof(struct Spell));
			fscanf(f,"%s %d %d %s",
				&(ThisSpell->Name),
				&(ThisSpell->TypeSpell),
				&(ThisSpell->Cooldown),
				&(ThisSpell->Bonuses)	//	struct Bonus *Bonuses;				
				);
			printf("ID's Spell : %s",ID);
			printf("\n");		
			printf("Name's Spell: %s",ThisSpell->Name);
			printf("\n");		
			printf("TypeSpell : %d",(ThisSpell->TypeSpell));
			printf("\n");		
			printf("Cooldown : %d",(ThisSpell->Cooldown));
			printf("\n");		
			printf("Bonuses : %s",(ThisSpell->Bonuses));
			free(ThisSpell);
		}
		else
		if(where==4){			
			struct Item *ThisItem;
			ThisItem=(struct Item *)malloc(sizeof(struct Item));			
			fscanf(f,"%s %d %d %d %d %s",
				&(ThisItem->Name),
				&(ThisItem->TypeItem),
				&(ThisItem->HealthPoint),
				&(ThisItem->Weight),
				&(ThisItem->Sharp),
				&(ThisItem->Bonuses)		//	struct Bonus *Bonuses;				
				);
			printf("ID's Item : %s",ID);
			printf("\n");		
			printf("Name's Item: %s",ThisItem->Name);			
			printf("\n");			
			printf("TypeItem : %d",(ThisItem->TypeItem));
			printf("\n");		
			printf("HealthPoint : %d",(ThisItem->HealthPoint));
			printf("\n");		
			printf("Weight : %d",(ThisItem->Weight));
			printf("\n");		
			printf("Sharp : %d",(ThisItem->Sharp));
			printf("\n");		
			printf("Bonuses : %s",(ThisItem->Bonuses));//	struct Bonus *Bonuses;
			free(ThisItem);
		}
		else
		if(where==5){									
			struct Player *ThiPlayer;
			ThiPlayer=(struct Player *)malloc(sizeof(struct Player));			
			fscanf(f,"%s %d %d %d %d %d %d %d %d %d",
				&(ThiPlayer->Account),
				&(ThiPlayer->Level),
				&(ThiPlayer->HP),
				&(ThiPlayer->Mana),
				&(ThiPlayer->Vitality),
				&(ThiPlayer->Strength),
				&(ThiPlayer->Agility),
				&(ThiPlayer->Intelligence),
				&(ThiPlayer->Defense),
				&(ThiPlayer->MovementSpeed)
				//	struct Equipment Equipment;
				//	struct Item *Inventory;
				);
			printf("Username's Player : %s",ID);
			printf("\n");		
			printf("Account's Player: %s",ThiPlayer->Account);
			printf("\n");	
			printf("Level's Player: %d",ThiPlayer->Level);
			printf("\n");
			printf("HP's Player: %d",ThiPlayer->HP);
			printf("\n");			
			printf("Mana : %d",(ThiPlayer->Mana));
			printf("\n");		
			printf("Vitality : %d",(ThiPlayer->Vitality));
			printf("\n");		
			printf("Strength : %d",(ThiPlayer->Strength));
			printf("\n");		
			printf("Agility : %d",(ThiPlayer->Agility));			
			printf("\n");
			printf("Intelligence : %d",(ThiPlayer->Intelligence));
			printf("\n");
			printf("Defense : %d",(ThiPlayer->Defense));
			printf("\n");
			printf("MovementSpeed : %d",(ThiPlayer->MovementSpeed));
			printf("\n");				
			printf("Equipment : %s","NULL");//	struct Equipment Equipment;
			printf("\n");	
			printf("Inventory : %s","NULL");//	struct Item *Inventory;			
			free(ThiPlayer);
		}
		fclose(f);
	}
	printf("\n");system("pause");
}

void afisaccount(int buffer, int ID,const char *Username,char * fcontent,int size,FILE *f){
	int i;
	for(i=0;i<5*buffer;i++)
	printf("=");
	printf("\n");
	printf("=");
	if(ID==0){	
		for(i=0;i<(buffer-strlen("ID")-2)/2;i++)
			printf(" ");
		printf("%s","ID");
		for(i=0;i<(buffer-strlen("ID")-2)/2;i++)
			printf(" ");
		printf("=");	
		printf("=");
		for(i=0;i<(buffer-strlen("Username")-2)/2;i++)
			printf(" ");
		printf("Username");
		for(i=0;i<(buffer-(strlen("Username")%2==0?(strlen("Username")):(strlen("Username")-1))-2)/2;i++)
			printf(" ");
		printf("=");
		printf("=");
		for(i=0;i<(buffer-strlen("Password")-2)/2;i++)
			printf(" ");
		printf("Password");
		for(i=0;i<(buffer-(strlen("Password")%2==0?(strlen("Password")):(strlen("Password")-1))-2)/2;i++)
			printf(" ");
		printf("=");
		printf("=");
		for(i=0;i<(buffer-strlen("Email")-2)/2;i++)
			printf(" ");
		printf("Email");
		for(i=0;i<(buffer-(strlen("Email")%2==0?(strlen("Email")):(strlen("Email")-1))-2)/2;i++)
			printf(" ");
		printf("=");
		printf("=");
		for(i=0;i<(buffer-strlen("Character")-2)/2;i++)
			printf(" ");
		printf("Character");
		for(i=0;i<(buffer-(strlen("Character")%2==0?(strlen("Character")):(strlen("Character")-1))-2)/2;i++)
			printf(" ");
		printf("=");
	}	
	else
	{
		char* auxiliar;		
		for(i=0;i<(buffer-((numarcifre(ID)%2)==0?(numarcifre(ID)):(numarcifre(ID)))-2)/2;i++)
			printf(" ");
		printf("%d",ID);
		for(i=0;i<(buffer-((numarcifre(ID)%2)==0?(numarcifre(ID)):(numarcifre(ID)-1))-2)/2;i++)
			printf(" ");
		printf("=");
		
		printf("=");
		for(i=0;i<(buffer-strlen(Username)-2)/2;i++)
			printf(" ");
		printf(Username);
		for(i=0;i<(buffer-(strlen(Username)%2==0?(strlen(Username)):(strlen(Username)-1))-2)/2;i++)
			printf(" ");
		printf("=");
		
		auxiliar=getinfo(fcontent,size,f);		
		printf("=");
		for(i=0;i<(buffer-strlen(auxiliar)-2)/2;i++)
			printf(" ");
		printf(auxiliar);
		for(i=0;i<(buffer-(strlen(auxiliar)%2==0?(strlen(auxiliar)):(strlen(auxiliar)-1))-2)/2;i++)
			printf(" ");
		printf("=");
		
		auxiliar=getinfo(fcontent,size,f);		
		printf("=");
		for(i=0;i<(buffer-strlen(auxiliar)-2)/2;i++)
			printf(" ");
		printf(auxiliar);
		for(i=0;i<(buffer-(strlen(auxiliar)%2==0?(strlen(auxiliar)):(strlen(auxiliar)-1))-2)/2;i++)
			printf(" ");
		printf("=");
		
		auxiliar=getinfo(fcontent,size,f);
		printf("=");
		for(i=0;i<(buffer-strlen(auxiliar)-2)/2;i++)
			printf(" ");
		printf(auxiliar);
		for(i=0;i<(buffer-(strlen(auxiliar)%2==0?(strlen(auxiliar)):(strlen(auxiliar)-1))-2)/2;i++)
			printf(" ");
		printf("=");
		
		free(auxiliar);
	}	
	printf("\n");
	for(i=0;i<5*buffer;i++)
		printf("=");
}
void afisbonus(int buffer,int ok,struct Bonus *ThisBonus,int size){
	int i;
	for(i=0;i<5*buffer;i++)
	printf("=");
	printf("\n");
	printf("=");
	if(ok==0){
		for(i=0;i<(buffer-strlen("ID")-2)/2;i++)
			printf(" ");
		printf("%s","ID");
		for(i=0;i<(buffer-strlen("ID")-2)/2;i++)
			printf(" ");
		printf("=");	
		printf("=");
		for(i=0;i<(buffer-strlen("Name")-2)/2;i++)
			printf(" ");
		printf("Name");
		for(i=0;i<(buffer-(strlen("Name")%2==0?(strlen("Name")):(strlen("Name")-1))-2)/2;i++)
			printf(" ");
		printf("=");
		printf("=");
		for(i=0;i<(buffer-strlen("TypeBonus")-3)/2;i++)
			printf(" ");
		printf("TypeBonus");
		for(i=0;i<(buffer-(strlen("TypeBonus")%2==0?(strlen("TypeBonus")):(strlen("TypeBonus")-1))-2)/2;i++)
			printf(" ");
		printf("=");
		printf("=");
		for(i=0;i<(buffer-strlen("Value")-3)/2;i++)
			printf(" ");
		printf("Value");
		for(i=0;i<(buffer-(strlen("Value")%2==0?(strlen("Value")):(strlen("Value")-1))-2)/2;i++)
			printf(" ");
		printf("=");
		printf("=");
		for(i=0;i<(buffer-strlen("IsPercent")-3)/2;i++)
			printf(" ");
		printf("IsPercent");
		for(i=0;i<(buffer-(strlen("IsPercent")%2==0?(strlen("IsPercent")):(strlen("IsPercent")-1))-2)/2;i++)
			printf(" ");
		printf("=");
	}else
	{		
		for(i=0;i<(buffer-(strlen(ThisBonus[size].ID)==0?(strlen(ThisBonus[size].ID)):(strlen(ThisBonus[size].ID))-1)-2)/2;i++)
			printf(" ");
		printf("%s",ThisBonus[size].ID);
		for(i=0;i<(buffer-strlen(ThisBonus[size].ID)-2)/2;i++)
			printf(" ");
		printf("=");
		printf("=");
		for(i=0;i<(buffer-strlen(ThisBonus[size].Name)-2)/2;i++)
			printf(" ");
		printf(ThisBonus[size].Name);
		for(i=0;i<(buffer-(strlen(ThisBonus[size].Name)%2==0?(strlen(ThisBonus[size].Name)):(strlen(ThisBonus[size].Name)-1))-2)/2;i++)
			printf(" ");
		printf("=");
		printf("=");
		for(i=0;i<(buffer-((numarcifre(ThisBonus[size].TypeBonus)%2)==0?(numarcifre(ThisBonus[size].TypeBonus)):(numarcifre(ThisBonus[size].TypeBonus)))-2)/2;i++)
			printf(" ");
		printf("%d",ThisBonus[size].TypeBonus);
		for(i=0;i<(buffer-((numarcifre(ThisBonus[size].TypeBonus)%2)==0?(numarcifre(ThisBonus[size].TypeBonus)):(numarcifre(ThisBonus[size].TypeBonus)-1))-2)/2;i++)
			printf(" ");
		printf("=");
		printf("=");
		for(i=0;i<(buffer-((numarcifre(ThisBonus[size].value)%2)==0?(numarcifre(ThisBonus[size].value)):(numarcifre(ThisBonus[size].value)))-2)/2;i++)
			printf(" ");
		printf("%d",ThisBonus[size].value);
		for(i=0;i<(buffer-((numarcifre(ThisBonus[size].value)%2)==0?(numarcifre(ThisBonus[size].value)):(numarcifre(ThisBonus[size].value)-1))-2)/2;i++)
			printf(" ");
		printf("=");
		printf("=");
		if(ThisBonus[size].IsPercent==0){
			for(i=0;i<((buffer-strlen("false"))-2)/2;i++)
				printf(" ");		
			printf("false");
			for(i=0;i<(buffer-(strlen("false")%2==0?(strlen("false")):(strlen("false")-1))-2)/2;i++)
				printf(" ");
		} else
		{
			for(i=0;i<((buffer-strlen("true"))-2)/2;i++)
				printf(" ");
			printf("true");
			for(i=0;i<(buffer-(strlen("true")%2==0?(strlen("true")):(strlen("true")-1))-2)/2;i++)
				printf(" ");
		}
		printf("=");
		
	}	
	printf("\n");
	for(i=0;i<5*buffer;i++)
		printf("=");
}
void afisspell(int buffer,int ok,struct Spell *ThisSpell,int size){
	int i;
	for(i=0;i<5*buffer;i++)
	printf("=");
	printf("\n");
	printf("=");
	if(ok==0){
		for(i=0;i<(buffer-strlen("ID")-2)/2;i++)
			printf(" ");
		printf("%s","ID");
		for(i=0;i<(buffer-strlen("ID")-2)/2;i++)
			printf(" ");
		printf("=");	
		printf("=");
		for(i=0;i<(buffer-strlen("Name")-2)/2;i++)
			printf(" ");
		printf("Name");
		for(i=0;i<(buffer-(strlen("Name")%2==0?(strlen("Name")):(strlen("Name")-1))-2)/2;i++)
			printf(" ");
		printf("=");
		printf("=");
		for(i=0;i<(buffer-strlen("TypeSpell")-3)/2;i++)
			printf(" ");
		printf("TypeSpell");
		for(i=0;i<(buffer-(strlen("TypeSpell")%2==0?(strlen("TypeSpell")):(strlen("TypeSpell")-1))-2)/2;i++)
			printf(" ");
		printf("=");
		printf("=");
		for(i=0;i<(buffer-strlen("Cooldown")-2)/2;i++)
			printf(" ");
		printf("Cooldown");
		for(i=0;i<(buffer-(strlen("Cooldown")%2==0?(strlen("Cooldown")):(strlen("Cooldown")-1))-2)/2;i++)
			printf(" ");
		printf("=");
		printf("=");
		for(i=0;i<(buffer-strlen("Bonuses")-3)/2;i++)
			printf(" ");
		printf("Bonuses");
		for(i=0;i<(buffer-(strlen("Bonuses")%2==0?(strlen("Bonuses")):(strlen("Bonuses")-1))-2)/2;i++)
			printf(" ");
		printf("=");
	}else
	{		
		for(i=0;i<(buffer-(strlen(ThisSpell[size].ID)==0?(strlen(ThisSpell[size].ID)):(strlen(ThisSpell[size].ID))-1)-2)/2;i++)
			printf(" ");
		printf("%s",ThisSpell[size].ID);
		for(i=0;i<(buffer-strlen(ThisSpell[size].ID)-2)/2;i++)
			printf(" ");
		printf("=");
		printf("=");
		for(i=0;i<(buffer-strlen(ThisSpell[size].Name)-2)/2;i++)
			printf(" ");
		printf(ThisSpell[size].Name);
		for(i=0;i<(buffer-(strlen(ThisSpell[size].Name)%2==0?(strlen(ThisSpell[size].Name)):(strlen(ThisSpell[size].Name)-1))-2)/2;i++)
			printf(" ");
		printf("=");
		printf("=");
		for(i=0;i<(buffer-((numarcifre(ThisSpell[size].TypeSpell)%2)==0?(numarcifre(ThisSpell[size].TypeSpell)):(numarcifre(ThisSpell[size].TypeSpell)))-2)/2;i++)
			printf(" ");
		printf("%d",ThisSpell[size].TypeSpell);
		for(i=0;i<(buffer-((numarcifre(ThisSpell[size].TypeSpell)%2)==0?(numarcifre(ThisSpell[size].TypeSpell)):(numarcifre(ThisSpell[size].TypeSpell)-1))-2)/2;i++)
			printf(" ");
		printf("=");
		printf("=");
		for(i=0;i<(buffer-((numarcifre(ThisSpell[size].Cooldown)%2)==0?(numarcifre(ThisSpell[size].Cooldown)):(numarcifre(ThisSpell[size].Cooldown)))-2)/2;i++)
			printf(" ");
		printf("%d",ThisSpell[size].Cooldown);
		for(i=0;i<(buffer-((numarcifre(ThisSpell[size].Cooldown)%2)==0?(numarcifre(ThisSpell[size].Cooldown)):(numarcifre(ThisSpell[size].Cooldown)-1))-2)/2;i++)
			printf(" ");
		printf("=");
		printf("=");
		for(i=0;i<(buffer-strlen(ThisSpell[size].Bonuses)-2)/2;i++)
			printf(" ");
		printf(ThisSpell[size].Bonuses);
		for(i=0;i<(buffer-(strlen(ThisSpell[size].Bonuses)%2==0?(strlen(ThisSpell[size].Bonuses)):(strlen(ThisSpell[size].Bonuses)-1))-2)/2;i++)
			printf(" ");
		printf("=");		
	}	
	printf("\n");
	for(i=0;i<5*buffer;i++)
		printf("=");
}
void afisitem(int buffer,int ok,struct Item *ThisItem,int size){
	int i;
	for(i=0;i<7*buffer;i++)
	printf("=");
	printf("\n");
	printf("=");
	if(ok==0){
		for(i=0;i<(buffer-strlen("ID")-2)/2;i++)
			printf(" ");
		printf("%s","ID");
		for(i=0;i<(buffer-strlen("ID")-2)/2;i++)
			printf(" ");
		printf("=");	
		printf("=");
		for(i=0;i<(buffer-strlen("Name")-2)/2;i++)
			printf(" ");
		printf("Name");
		for(i=0;i<(buffer-(strlen("Name")%2==0?(strlen("Name")):(strlen("Name")-1))-2)/2;i++)
			printf(" ");
		printf("=");		
		printf("=");
		for(i=0;i<(buffer-strlen("TypeItem")-2)/2;i++)
			printf(" ");
		printf("TypeItem");
		for(i=0;i<(buffer-(strlen("TypeItem")%2==0?(strlen("TypeItem")):(strlen("TypeItem")-1))-2)/2;i++)
			printf(" ");
		printf("=");
		printf("=");
		for(i=0;i<(buffer-strlen("HealthPoint")-3)/2;i++)
			printf(" ");
		printf("HealthPoint");
		for(i=0;i<(buffer-(strlen("HealthPoint")%2==0?(strlen("HealthPoint")):(strlen("HealthPoint")-1))-2)/2;i++)
			printf(" ");
		printf("=");
		printf("=");
		for(i=0;i<(buffer-strlen("Weight")-3)/2;i++)
			printf(" ");
		printf("Weight");
		for(i=0;i<(buffer-(strlen("Weight")%2==0?(strlen("Weight")):(strlen("Weight")-1))-2)/2;i++)
			printf(" ");
		printf("=");
		printf("=");
		for(i=0;i<(buffer-strlen("Sharp")-3)/2;i++)
			printf(" ");
		printf("Sharp");
		for(i=0;i<(buffer-(strlen("Sharp")%2==0?(strlen("Sharp")):(strlen("Sharp")-1))-2)/2;i++)
			printf(" ");
		printf("=");
		printf("=");
		for(i=0;i<(buffer-strlen("Bonuses")-3)/2;i++)
			printf(" ");
		printf("Bonuses");
		for(i=0;i<(buffer-(strlen("Bonuses")%2==0?(strlen("Bonuses")):(strlen("Bonuses")-1))-2)/2;i++)
			printf(" ");
		printf("=");		
	}else
	{		
		for(i=0;i<(buffer-(strlen(ThisItem[size].ID)==0?(strlen(ThisItem[size].ID)):(strlen(ThisItem[size].ID))-1)-2)/2;i++)
			printf(" ");
		printf("%s",ThisItem[size].ID);
		for(i=0;i<(buffer-strlen(ThisItem[size].ID)-2)/2;i++)
			printf(" ");
		printf("=");
		printf("=");
		for(i=0;i<(buffer-strlen(ThisItem[size].Name)-2)/2;i++)
			printf(" ");
		printf(ThisItem[size].Name);
		for(i=0;i<(buffer-(strlen(ThisItem[size].Name)%2==0?(strlen(ThisItem[size].Name)):(strlen(ThisItem[size].Name)-1))-2)/2;i++)
			printf(" ");
		printf("=");
		printf("=");
		for(i=0;i<(buffer-((numarcifre(ThisItem[size].TypeItem)%2)==0?(numarcifre(ThisItem[size].TypeItem)):(numarcifre(ThisItem[size].TypeItem)))-2)/2;i++)
			printf(" ");
		printf("%d",ThisItem[size].TypeItem);
		for(i=0;i<(buffer-((numarcifre(ThisItem[size].TypeItem)%2)==0?(numarcifre(ThisItem[size].TypeItem)):(numarcifre(ThisItem[size].TypeItem)-1))-2)/2;i++)
			printf(" ");
		printf("=");
		printf("=");
		for(i=0;i<(buffer-((numarcifre(ThisItem[size].HealthPoint)%2)==0?(numarcifre(ThisItem[size].HealthPoint)):(numarcifre(ThisItem[size].HealthPoint)))-2)/2;i++)
			printf(" ");
		printf("%d",ThisItem[size].HealthPoint);
		for(i=0;i<(buffer-((numarcifre(ThisItem[size].HealthPoint)%2)==0?(numarcifre(ThisItem[size].HealthPoint)):(numarcifre(ThisItem[size].HealthPoint)-1))-2)/2;i++)
			printf(" ");
		printf("=");
		printf("=");
		for(i=0;i<(buffer-((numarcifre(ThisItem[size].Weight)%2)==0?(numarcifre(ThisItem[size].Weight)):(numarcifre(ThisItem[size].Weight)))-2)/2;i++)
			printf(" ");
		printf("%d",ThisItem[size].Weight);
		for(i=0;i<(buffer-((numarcifre(ThisItem[size].Weight)%2)==0?(numarcifre(ThisItem[size].Weight)):(numarcifre(ThisItem[size].Weight)-1))-2)/2;i++)
			printf(" ");
		printf("=");
		printf("=");
		for(i=0;i<(buffer-((numarcifre(ThisItem[size].Sharp)%2)==0?(numarcifre(ThisItem[size].Sharp)):(numarcifre(ThisItem[size].Sharp)))-2)/2;i++)
			printf(" ");
		printf("%d",ThisItem[size].Sharp);
		for(i=0;i<(buffer-((numarcifre(ThisItem[size].Sharp)%2)==0?(numarcifre(ThisItem[size].Sharp)):(numarcifre(ThisItem[size].Sharp)-1))-2)/2;i++)
			printf(" ");
		printf("=");
		printf("=");
		for(i=0;i<(buffer-strlen(ThisItem[size].Bonuses)-2)/2;i++)
			printf(" ");
		printf(ThisItem[size].Bonuses);
		for(i=0;i<(buffer-(strlen(ThisItem[size].Bonuses)%2==0?(strlen(ThisItem[size].Bonuses)):(strlen(ThisItem[size].Bonuses)-1))-2)/2;i++)
			printf(" ");
		printf("=");	
	}	
	printf("\n");
	for(i=0;i<7*buffer;i++)
		printf("=");
}
void afisplayer(int buffer,int ok,struct Player *ThisPlayer,int size){
	int i;
	for(i=0;i<11*buffer;i++)
	printf("=");
	printf("\n");
	printf("=");
	if(ok==0){
		for(i=0;i<(buffer-strlen("Username")-2)/2;i++)
			printf(" ");
		printf("%s","Username");
		for(i=0;i<(buffer-(strlen("Username")%2==0?(strlen("Username")):(strlen("Username")-1))-2)/2;i++)
			printf(" ");
		printf("=");	
		printf("=");
		for(i=0;i<(buffer-strlen("Account")-2)/2;i++)
			printf(" ");
		printf("Account");
		for(i=0;i<(buffer-(strlen("Account")%2==0?(strlen("Account")):(strlen("Account")-1))-2)/2;i++)
			printf(" ");
		printf("=");
		printf("=");
		for(i=0;i<(buffer-strlen("Level")-3)/2;i++)
			printf(" ");
		printf("Level");
		for(i=0;i<(buffer-(strlen("Level")%2==0?(strlen("Level")):(strlen("Level")-1))-2)/2;i++)
			printf(" ");
		printf("=");
		printf("=");
		for(i=0;i<(buffer-strlen("HP")-2)/2;i++)
			printf(" ");
		printf("HP");
		for(i=0;i<(buffer-(strlen("HP")%2==0?(strlen("HP")):(strlen("HP")-1))-2)/2;i++)
			printf(" ");
		printf("=");
		printf("=");
		for(i=0;i<(buffer-strlen("Mana")-2)/2;i++)
			printf(" ");
		printf("Mana");
		for(i=0;i<(buffer-(strlen("Mana")%2==0?(strlen("Mana")):(strlen("Mana")-1))-2)/2;i++)
			printf(" ");
		printf("=");
		printf("=");
		for(i=0;i<(buffer-strlen("Vitality")-2)/2;i++)
			printf(" ");
		printf("Vitality");
		for(i=0;i<(buffer-(strlen("Vitality")%2==0?(strlen("Vitality")):(strlen("Vitality")-1))-2)/2;i++)
			printf(" ");
		printf("=");
		printf("=");
		for(i=0;i<(buffer-strlen("Strength")-2)/2;i++)
			printf(" ");
		printf("Strength");
		for(i=0;i<(buffer-(strlen("Strength")%2==0?(strlen("Strength")):(strlen("Strength")-1))-2)/2;i++)
			printf(" ");
		printf("=");
		printf("=");
		for(i=0;i<(buffer-strlen("Agility")-3)/2;i++)
			printf(" ");
		printf("Agility");
		for(i=0;i<(buffer-(strlen("Agility")%2==0?(strlen("Agility")):(strlen("Agility")-1))-2)/2;i++)
			printf(" ");
		printf("=");
		printf("=");
		for(i=0;i<(buffer-strlen("Intelligence")-2)/2;i++)
			printf(" ");
		printf("Intelligence");
		for(i=0;i<(buffer-(strlen("Intelligence")%2==0?(strlen("Intelligence")):(strlen("Intelligence")-1))-2)/2;i++)
			printf(" ");
		printf("=");
		printf("=");
		for(i=0;i<(buffer-strlen("Defense")-3)/2;i++)
			printf(" ");
		printf("Defense");
		for(i=0;i<(buffer-(strlen("Defense")%2==0?(strlen("Defense")):(strlen("Defense")-1))-2)/2;i++)
			printf(" ");
		printf("=");
		printf("=");
		for(i=0;i<(buffer-strlen("MovementSpeed")-3)/2;i++)
			printf(" ");
		printf("MovementSpeed");
		for(i=0;i<(buffer-(strlen("MovementSpeed")%2==0?(strlen("MovementSpeed")):(strlen("MovementSpeed")-1))-2)/2;i++)
			printf(" ");
		printf("=");

	}else
	{			
		for(i=0;i<(buffer-(strlen(ThisPlayer[size].Username)%2==0?(strlen(ThisPlayer[size].Username)+2):(strlen(ThisPlayer[size].Username))))/2;i++)
			printf(" ");
		printf("%s",ThisPlayer[size].Username);
		for(i=0;i<(buffer-strlen(ThisPlayer[size].Username)-2)/2;i++)
			printf(" ");
		printf("=");
		printf("=");
		for(i=0;i<(buffer-(strlen(ThisPlayer[size].Account)%2==0?((strlen(ThisPlayer[size].Account))+2):((strlen(ThisPlayer[size].Account)))))/2;i++)
			printf(" ");
		printf(ThisPlayer[size].Account);
		for(i=0;i<(buffer-strlen(ThisPlayer[size].Account)-2)/2;i++)
			printf(" ");
		printf("=");
		printf("=");
		for(i=0;i<(buffer-(numarcifre(ThisPlayer[size].Level)%2==0?(numarcifre(ThisPlayer[size].Level)+2):(numarcifre(ThisPlayer[size].Level))))/2;i++)
			printf(" ");
		printf("%d",ThisPlayer[size].Level);
		for(i=0;i<(buffer-(numarcifre(ThisPlayer[size].Level))-2)/2;i++)
			printf(" ");
		printf("=");
		printf("=");
		for(i=0;i<(buffer-(numarcifre(ThisPlayer[size].HP)%2==0?((numarcifre(ThisPlayer[size].HP))+2):((numarcifre(ThisPlayer[size].HP)))))/2;i++)
			printf(" ");
		printf("%d",ThisPlayer[size].HP);
		for(i=0;i<(buffer-((numarcifre(ThisPlayer[size].HP)))-2)/2;i++)
			printf(" ");
		printf("=");
		printf("=");
		for(i=0;i<(buffer-(numarcifre(ThisPlayer[size].Mana)%2==0?((numarcifre(ThisPlayer[size].Mana))+2):((numarcifre(ThisPlayer[size].Mana)))))/2;i++)
			printf(" ");
		printf("%d",ThisPlayer[size].Mana);
		for(i=0;i<(buffer-((numarcifre(ThisPlayer[size].Mana)))-2)/2;i++)
			printf(" ");
		printf("=");
		printf("=");
		for(i=0;i<(buffer-(numarcifre(ThisPlayer[size].Vitality)%2==0?((numarcifre(ThisPlayer[size].Vitality))+2):((numarcifre(ThisPlayer[size].Vitality)))))/2;i++)
			printf(" ");
		printf("%d",ThisPlayer[size].Vitality);
		for(i=0;i<(buffer-((numarcifre(ThisPlayer[size].Vitality)))-2)/2;i++)
			printf(" ");
		printf("=");
		printf("=");
		for(i=0;i<(buffer-(numarcifre(ThisPlayer[size].Strength)%2==0?((numarcifre(ThisPlayer[size].Strength))+2):((numarcifre(ThisPlayer[size].Strength)))))/2;i++)
			printf(" ");
		printf("%d",ThisPlayer[size].Strength);
		for(i=0;i<(buffer-((numarcifre(ThisPlayer[size].Strength)))-2)/2;i++)
			printf(" ");
		printf("=");
		printf("=");
		for(i=0;i<(buffer-(numarcifre(ThisPlayer[size].Agility)%2==0?((numarcifre(ThisPlayer[size].Agility))+2):((numarcifre(ThisPlayer[size].Agility)))))/2;i++)
			printf(" ");
		printf("%d",ThisPlayer[size].Agility);
		for(i=0;i<(buffer-((numarcifre(ThisPlayer[size].Agility)))-2)/2;i++)
			printf(" ");
		printf("=");		
		printf("=");
		for(i=0;i<(buffer-(numarcifre(ThisPlayer[size].Intelligence)%2==0?((numarcifre(ThisPlayer[size].Intelligence))+2):((numarcifre(ThisPlayer[size].Intelligence)))))/2;i++)
			printf(" ");
		printf("%d",ThisPlayer[size].Intelligence);
		for(i=0;i<(buffer-((numarcifre(ThisPlayer[size].Intelligence)))-2)/2;i++)
			printf(" ");
		printf("=");
		printf("=");
		for(i=0;i<(buffer-(numarcifre(ThisPlayer[size].Defense)%2==0?((numarcifre(ThisPlayer[size].Defense))+2):((numarcifre(ThisPlayer[size].Defense)))))/2;i++)
			printf(" ");
		printf("%d",ThisPlayer[size].Defense);
		for(i=0;i<(buffer-((numarcifre(ThisPlayer[size].Defense)))-2)/2;i++)
			printf(" ");
		printf("=");		
		printf("=");
		for(i=0;i<(buffer-(numarcifre(ThisPlayer[size].MovementSpeed)%2==0?((numarcifre(ThisPlayer[size].MovementSpeed))+2):((numarcifre(ThisPlayer[size].MovementSpeed)))))/2;i++)
			printf(" ");
		printf("%d",ThisPlayer[size].MovementSpeed);
		for(i=0;i<(buffer-((numarcifre(ThisPlayer[size].MovementSpeed)))-2)/2;i++)
			printf(" ");
		printf("=");		
	}	
	printf("\n");
	for(i=0;i<11*buffer;i++)
		printf("=");
}

void listaccounts(char*Directory){
	int j,buffer=20;
	printf("List Accounts:\n");
	printf("!? Warning ?! If somehow the message seen wrong magnify the window !!\n");
	afisaccount(buffer,0,"Username",NULL,0,NULL);
    DIR *pDIR;
    struct dirent *entry;
	j=1;
    if( pDIR=opendir(Directory) ){
        while(entry = readdir(pDIR)){
			if(strcmp(entry->d_name, "..") != 0 && (strcmp(entry->d_name, ".") != 0)){				
				FILE *f;
				char *ThisFile;
				ThisFile = (char*)malloc(sizeof(char)*(strlen(Directory)+strlen(entry->d_name)));
				strcpy(ThisFile,Directory);
				strcat(ThisFile,entry->d_name);
				f=fopen(ThisFile,"r");
				printf("\n");
				char *fcontent;
				fcontent = (char *)malloc(filesize(ThisFile)*sizeof(char));									
				afisaccount(buffer,j,entry->d_name,fcontent,(1+filesize(ThisFile)),f);	
				free(ThisFile);
				fclose(f);	
				free(f);									
				free(fcontent);							
				j++;									
			}
        }
        closedir(pDIR);
    }	
	printf("\n");
	system("pause");
}
void listbonuses(char*Directory){
	int j,buffer=20;
	printf("List Bonuses:\n");
	printf("!? Warning ?! If somehow the message seen wrong magnify the window !!\n");
	struct Bonus *ThisBonus;	
	afisbonus(buffer,0,NULL,0);
    DIR *pDIR;
    struct dirent *entry;	
    if( pDIR=opendir(Directory) ){
        while(entry = readdir(pDIR)){
			if(strcmp(entry->d_name, "..") != 0 && (strcmp(entry->d_name, ".") != 0)){				
				FILE *f;
				char *ThisFile;
				ThisFile = (char*)malloc(sizeof(char)*(strlen(Directory)+strlen(entry->d_name)));
				strcpy(ThisFile,Directory);
				strcat(ThisFile,entry->d_name);
				f=fopen(ThisFile,"r");
				printf("\n");
				char *fcontent;
				fcontent = (char *)malloc(filesize(ThisFile)*sizeof(char));		
				ThisBonus=(struct Bonus*)malloc(sizeof(struct Bonus));
				strcpy(ThisBonus->ID,entry->d_name);			
				strcpy(ThisBonus->Name,getinfo(fcontent,(1+filesize(ThisFile)),f));			
				int *aux;
				aux=(int*)malloc(sizeof(int));
				fscanf(f,"%d",&aux);				
				ThisBonus->TypeBonus=(unsigned int)aux;						
				fscanf(f,"%d",&aux);				
				ThisBonus->value=(unsigned int)aux;							
				fscanf(f,"%d",&aux);				
				ThisBonus->IsPercent=(unsigned int)aux;				
				free(aux);								
				afisbonus(buffer,1,ThisBonus,0);				
				free(ThisBonus);
				free(ThisFile);
				fclose(f);	
				free(f);									
				free(fcontent);																
			}
        }
        closedir(pDIR);
    }	
	printf("\n");
	system("pause");
}	
void listspells(char*Directory){
	int j,buffer=20;
	printf("List Spells:\n");
	printf("!? Warning ?! If somehow the message seen wrong magnify the window !!\n");
	struct Spell *ThisSpell;	
	afisspell(buffer,0,NULL,0);
    DIR *pDIR;
    struct dirent *entry;	
    if( pDIR=opendir(Directory) ){
        while(entry = readdir(pDIR)){
			if(strcmp(entry->d_name, "..") != 0 && (strcmp(entry->d_name, ".") != 0)){				
				FILE *f;
				char *ThisFile;
				ThisFile = (char*)malloc(sizeof(char)*(strlen(Directory)+strlen(entry->d_name)));
				strcpy(ThisFile,Directory);
				strcat(ThisFile,entry->d_name);
				f=fopen(ThisFile,"r");
				printf("\n");
				char *fcontent;
				fcontent = (char *)malloc(filesize(ThisFile)*sizeof(char));		
				ThisSpell=(struct Spell*)malloc(sizeof(struct Spell));
				strcpy(ThisSpell->ID,entry->d_name);			
				strcpy(ThisSpell->Name,getinfo(fcontent,(1+filesize(ThisFile)),f));	
				fscanf(f,"%d",&(ThisSpell->TypeSpell));
				fscanf(f,"%d",&(ThisSpell->Cooldown));
				fscanf(f,"%s",&(ThisSpell->Bonuses)); //	struct Bonus *Bonuses;
				afisspell(buffer,1,ThisSpell,0);				
				free(ThisSpell);
				free(ThisFile);
				fclose(f);	
				free(f);									
				free(fcontent);																
			}
        }
        closedir(pDIR);
    }	
	printf("\n");
	system("pause");
}	
void listitems(char*Directory){
	int j,buffer=20;
	printf("List Spells:\n");
	printf("!? Warning ?! If somehow the message seen wrong magnify the window !!\n");
	struct Item *ThisItem;	
	afisitem(buffer,0,NULL,0);
    DIR *pDIR;
    struct dirent *entry;	
    if( pDIR=opendir(Directory) ){
        while(entry = readdir(pDIR)){
			if(strcmp(entry->d_name, "..") != 0 && (strcmp(entry->d_name, ".") != 0)){				
				FILE *f;
				char *ThisFile;
				ThisFile = (char*)malloc(sizeof(char)*(strlen(Directory)+strlen(entry->d_name)));
				strcpy(ThisFile,Directory);
				strcat(ThisFile,entry->d_name);
				f=fopen(ThisFile,"r");
				printf("\n");
				char *fcontent;				
				fcontent = (char *)malloc(filesize(ThisFile)*sizeof(char));		
				ThisItem=(struct Item*)malloc(sizeof(struct Item));
				strcpy(ThisItem->ID,entry->d_name);			
				fscanf(f,"%s %d %d %d %d %s",
					&(ThisItem->Name),
					&(ThisItem->TypeItem),
					&(ThisItem->HealthPoint),
					&(ThisItem->Weight),
					&(ThisItem->Sharp),
					&(ThisItem->Bonuses) 	//	struct Bonus *Bonuses;
					);				
				afisitem(buffer,1,ThisItem,0);				
				free(ThisItem);
				free(ThisFile);
				fclose(f);	
				free(f);									
				free(fcontent);																
			}
        }
        closedir(pDIR);
    }	
	printf("\n");
	system("pause");
}
void listplayers(char*Directory){
	int buffer=18;
	printf("List Spells:\n");
	printf("!? Warning ?! If somehow the message seen wrong magnify the window !!\n");
	struct Player *ThisPlayer;	
	afisplayer(buffer,0,NULL,0);
    DIR *pDIR;
    struct dirent *entry;	
    if( pDIR=opendir(Directory) ){
        while(entry = readdir(pDIR)){
			if(strcmp(entry->d_name, "..") != 0 && (strcmp(entry->d_name, ".") != 0)){				
				FILE *f;
				char *ThisFile;
				ThisFile = (char*)malloc(sizeof(char)*(strlen(Directory)+strlen(entry->d_name)));
				strcpy(ThisFile,Directory);
				strcat(ThisFile,entry->d_name);
				f=fopen(ThisFile,"r");
				printf("\n");
				char *fcontent;				
				fcontent = (char *)malloc(filesize(ThisFile)*sizeof(char));		
				ThisPlayer=(struct Player*)malloc(sizeof(struct Player));
				strcpy(ThisPlayer->Username,entry->d_name);				
				fscanf(f,"%s %d %d %d %d %d %d %d %d %d %s %s",
					&(ThisPlayer->Account),
					&(ThisPlayer->Level),
					&(ThisPlayer->HP),
					&(ThisPlayer->Mana),
					&(ThisPlayer->Vitality),
					&(ThisPlayer->Strength),
					&(ThisPlayer->Agility),
					&(ThisPlayer->Intelligence),
					&(ThisPlayer->Defense),
					&(ThisPlayer->MovementSpeed),
					&(ThisPlayer->Equipment),		//	struct Equipment Equipment;
					&(ThisPlayer->Inventory)		//	struct Item *Inventory;					
					);				
				afisplayer(buffer,1,ThisPlayer,0);				
				free(ThisPlayer);
				free(ThisFile);
				fclose(f);	
				free(f);									
				free(fcontent);																
			}
        }
        closedir(pDIR);
    }	
	printf("\n");
	system("pause");
}

void orderaccount(char* Order){
	if(strcmp(Order,"Email")==0){
		printf("Order by Email\n");
	}
	else
	if(strcmp(Order,"Character")==0){
		printf("Order by Character\n");
	}
	int i,j,buffer=20;
    DIR *pDIR;
    struct dirent *entry;
	i=0;		
	if( pDIR=opendir(LoginDirectory) ){
        while(entry = readdir(pDIR)){
			if(strcmp(entry->d_name, "..") != 0 && (strcmp(entry->d_name, ".") != 0)){										
				i++;									
			}
        }
        closedir(pDIR);
    }		
	struct Account *Accounts;
	Accounts=(struct Account*)malloc(i*sizeof(struct Account));
	j=0;	
	if( pDIR=opendir(LoginDirectory) ){
        while(entry = readdir(pDIR)){
			if(strcmp(entry->d_name, "..") != 0 && (strcmp(entry->d_name, ".") != 0)){				
				FILE *f;
				char *ThisFile;
				ThisFile = (char*)malloc(sizeof(char)*(strlen(LoginDirectory)+strlen(entry->d_name)));
				strcpy(ThisFile,LoginDirectory);
				strcat(ThisFile,entry->d_name);
				f=fopen(ThisFile,"r");								
				char *fcontent;
				fcontent = (char *)malloc(filesize(ThisFile)*sizeof(char));
				/*
				char aux[30];
				strcpy(aux,(entry->d_name));
				strcpy(Accounts[j].Username,aux);	
				*/
				strcpy(Accounts[j].Username,(char*)(entry->d_name));	
				fgets(fcontent,(1+filesize(ThisFile)),f);
				strtok(fcontent,"\n");
				strcpy(Accounts[j].Password,fcontent);
				fgets(fcontent,(1+filesize(ThisFile)),f);
				strtok(fcontent,"\n");
				strcpy(Accounts[j].Email,fcontent);
				fgets(fcontent,(1+filesize(ThisFile)),f);
				strtok(fcontent,"\n");
				strcpy(Accounts[j].Character,fcontent);							
				free(ThisFile);
				fclose(f);	
				free(f);									
				free(fcontent);							
				j++;			
			}
        }
		closedir(pDIR);
    }
	if(strcmp(Order,"Email")==0){
		qsort(Accounts,j,sizeof(struct Account),compareaccountEmail);
	}
	else
	if(strcmp(Order,"Character")==0){
		qsort(Accounts,j,sizeof(struct Account),compareaccountCharacter);
	}	
	displayaccounts(Accounts,j-1,30);	
	free(Accounts);
	printf("\n");
	system("pause");
}
void orderbonus(char* Order){
	int j,buffer=20;
	if(strcmp(Order,"Name")==0){
		printf("Order by Name:\n");
	}
	else
	if(strcmp(Order,"TypeBonus")==0){
		printf("Order by TypeBonus\n");
	}	
	printf("!? Warning ?! If somehow the message seen wrong magnify the window !!\n");
	struct Bonus *ThisBonus;	
	afisbonus(buffer,0,NULL,0);
    DIR *pDIR;
    struct dirent *entry;		
	j=0;
    if( pDIR=opendir(BonusDirectory) ){
        while(entry = readdir(pDIR)){
			if(strcmp(entry->d_name, "..") != 0 && (strcmp(entry->d_name, ".") != 0)){				
				j++;								
			}
        }
        closedir(pDIR);
    }
	ThisBonus=(struct Bonus*)malloc(j*sizeof(struct Bonus));
	j=0;
	if( pDIR=opendir(BonusDirectory) ){
        while(entry = readdir(pDIR)){
			if(strcmp(entry->d_name, "..") != 0 && (strcmp(entry->d_name, ".") != 0)){				
				FILE *f;
				char *ThisFile;
				ThisFile = (char*)malloc(sizeof(char)*(strlen(BonusDirectory)+strlen(entry->d_name)));
				strcpy(ThisFile,BonusDirectory);
				strcat(ThisFile,entry->d_name);
				f=fopen(ThisFile,"r");				
				char *fcontent;
				fcontent = (char *)malloc(filesize(ThisFile)*sizeof(char));						
				strcpy((ThisBonus+j)->ID,entry->d_name);			
				strcpy((ThisBonus+j)->Name,getinfo(fcontent,(1+filesize(ThisFile)),f));			
				int *aux;
				aux=(int*)malloc(sizeof(int));
				fscanf(f,"%d",&aux);				
				(ThisBonus+j)->TypeBonus=(unsigned int)aux;						
				fscanf(f,"%d",&aux);				
				(ThisBonus+j)->value=(unsigned int)aux;							
				fscanf(f,"%d",&aux);				
				(ThisBonus+j)->IsPercent=(unsigned int)aux;				
				free(aux);							
				free(ThisFile);
				fclose(f);	
				free(f);									
				free(fcontent);	
				j++;				
			}
        }
        closedir(pDIR);
    }
	int i=0;
	printf("\n");	
	if(strcmp(Order,"Name")==0){
	qsort(ThisBonus,j,sizeof(struct Bonus),comparebonusName);
	}	
	else
	if(strcmp(Order,"TypeBonus")==0){
	qsort(ThisBonus,j,sizeof(struct Bonus),comparebonusTypeBonus);
	}
	for(i=0;i<j;i++){
		afisbonus(buffer,1,ThisBonus,i);
		printf("\n");
	}
	free(ThisBonus);
	printf("\n");
	system("pause");
}
void orderspell(char* Order){
int j,buffer=20;
	if(strcmp(Order,"Name")==0){
		printf("Order by Name:\n");
	}
	else
	if(strcmp(Order,"TypeSpell")==0){
		printf("Order by TypeSpell\n");
	}	
	printf("!? Warning ?! If somehow the message seen wrong magnify the window !!\n");
	struct Spell *ThisSpell;	
	afisspell(buffer,0,NULL,0);
    DIR *pDIR;
    struct dirent *entry;		
	j=0;
    if( pDIR=opendir(SpellDirectory) ){
        while(entry = readdir(pDIR)){
			if(strcmp(entry->d_name, "..") != 0 && (strcmp(entry->d_name, ".") != 0)){				
				j++;								
			}
        }
        closedir(pDIR);
    }
	ThisSpell=(struct Spell*)malloc(j*sizeof(struct Spell));
	j=0;
	if( pDIR=opendir(SpellDirectory) ){
        while(entry = readdir(pDIR)){
			if(strcmp(entry->d_name, "..") != 0 && (strcmp(entry->d_name, ".") != 0)){				
				FILE *f;
				char *ThisFile;
				ThisFile = (char*)malloc(sizeof(char)*(strlen(SpellDirectory)+strlen(entry->d_name)));
				strcpy(ThisFile,SpellDirectory);
				strcat(ThisFile,entry->d_name);
				f=fopen(ThisFile,"r");				
				char *fcontent;				
				fcontent = (char *)malloc(filesize(ThisFile)*sizeof(char));
				strcpy((ThisSpell+j)->ID,entry->d_name);			
				strcpy((ThisSpell+j)->Name,getinfo(fcontent,(1+filesize(ThisFile)),f));	
				fscanf(f,"%d",&((ThisSpell+j)->TypeSpell));
				fscanf(f,"%d",&((ThisSpell+j)->Cooldown));
				fscanf(f,"%s",&((ThisSpell+j)->Bonuses)); //	struct Bonus *Bonuses;	
				free(ThisFile);
				fclose(f);	
				free(f);									
				free(fcontent);	
				j++;				
			}
        }
        closedir(pDIR);
    }
	int i=0;
	printf("\n");	
	if(strcmp(Order,"Name")==0){
	qsort(ThisSpell,j,sizeof(struct Spell),comparespellName);
	}	
	else
	if(strcmp(Order,"TypeSpell")==0){
	qsort(ThisSpell,j,sizeof(struct Spell),comparespellTypeSpell);
	}
	for(i=0;i<j;i++){
		afisspell(buffer,1,ThisSpell,i);
		printf("\n");
	}
	free(ThisSpell);
	printf("\n");
	system("pause");
}
void orderitem(char* Order){
int j,buffer=20;
	if(strcmp(Order,"Name")==0){
		printf("Order by Name:\n");
	}
	else
	if(strcmp(Order,"TypeItem")==0){
		printf("Order by TypeItem\n");
	}	
	printf("!? Warning ?! If somehow the message seen wrong magnify the window !!\n");
	struct Item *ThisItem;	
	afisitem(buffer,0,NULL,0);
    DIR *pDIR;
    struct dirent *entry;		
	j=0;
    if( pDIR=opendir(ItemDirectory) ){
        while(entry = readdir(pDIR)){
			if(strcmp(entry->d_name, "..") != 0 && (strcmp(entry->d_name, ".") != 0)){				
				j++;								
			}
        }
        closedir(pDIR);
    }
	ThisItem=(struct Item*)malloc(j*sizeof(struct Item));
	j=0;
	if( pDIR=opendir(ItemDirectory) ){
        while(entry = readdir(pDIR)){
			if(strcmp(entry->d_name, "..") != 0 && (strcmp(entry->d_name, ".") != 0)){				
				FILE *f;
				char *ThisFile;
				ThisFile = (char*)malloc(sizeof(char)*(strlen(ItemDirectory)+strlen(entry->d_name)));
				strcpy(ThisFile,ItemDirectory);
				strcat(ThisFile,entry->d_name);
				f=fopen(ThisFile,"r");	
				char *fcontent;				
				fcontent = (char *)malloc(filesize(ThisFile)*sizeof(char));				
				strcpy((ThisItem+j)->ID,entry->d_name);			
				fscanf(f,"%s %d %d %d %d %s",
					&((ThisItem+j)->Name),
					&((ThisItem+j)->TypeItem),
					&((ThisItem+j)->HealthPoint),
					&((ThisItem+j)->Weight),
					&((ThisItem+j)->Sharp),
					&((ThisItem+j)->Bonuses) 	//	struct Bonus *Bonuses;
					);					
				free(ThisFile);
				fclose(f);	
				free(f);									
				free(fcontent);	
				j++;				
			}
        }
        closedir(pDIR);
    }
	int i=0;
	printf("\n");	
	if(strcmp(Order,"Name")==0){
	qsort(ThisItem,j,sizeof(struct Item),compareitemName);
	}	
	else
	if(strcmp(Order,"TypeItem")==0){
	qsort(ThisItem,j,sizeof(struct Item),compareitemTypeItem);
	}
	for(i=0;i<j;i++){
		afisitem(buffer,1,ThisItem,i);
		printf("\n");
	}
	free(ThisItem);
	printf("\n");
	system("pause");
}
void orderplayer(char* Order){
	int j,buffer=18;
	if(strcmp(Order,"Account")==0){
		printf("Order by Account:\n");
	}
	printf("!? Warning ?! If somehow the message seen wrong magnify the window !!\n");
	struct Player *ThisPlayer;	
	afisplayer(buffer,0,NULL,0);
    DIR *pDIR;
    struct dirent *entry;		
	j=0;
    if( pDIR=opendir(PlayerDirectory) ){
        while(entry = readdir(pDIR)){
			if(strcmp(entry->d_name, "..") != 0 && (strcmp(entry->d_name, ".") != 0)){				
				j++;								
			}
        }
        closedir(pDIR);
    }
	ThisPlayer=(struct Player*)malloc(j*sizeof(struct Player));
	j=0;
	if( pDIR=opendir(PlayerDirectory) ){
        while(entry = readdir(pDIR)){
			if(strcmp(entry->d_name, "..") != 0 && (strcmp(entry->d_name, ".") != 0)){				
				FILE *f;
				char *ThisFile;
				ThisFile = (char*)malloc(sizeof(char)*(strlen(PlayerDirectory)+strlen(entry->d_name)));
				strcpy(ThisFile,PlayerDirectory);
				strcat(ThisFile,entry->d_name);
				f=fopen(ThisFile,"r");	
				char *fcontent;				
				fcontent = (char *)malloc(filesize(ThisFile)*sizeof(char));				
				strcpy((ThisPlayer+j)->Username,entry->d_name);			
				fscanf(f,"%s %d %d %d %d %d %d %d %d %d %s %s",
					&((ThisPlayer+j)->Account),
					&((ThisPlayer+j)->Level),
					&((ThisPlayer+j)->HP),
					&((ThisPlayer+j)->Mana),
					&((ThisPlayer+j)->Vitality),
					&((ThisPlayer+j)->Strength),
					&((ThisPlayer+j)->Agility),
					&((ThisPlayer+j)->Intelligence),
					&((ThisPlayer+j)->Defense),
					&((ThisPlayer+j)->MovementSpeed),
					&((ThisPlayer+j)->Equipment),		//	struct Equipment Equipment;
					&((ThisPlayer+j)->Inventory)		//	struct Item *Inventory;					
					);					
				free(ThisFile);
				fclose(f);	
				free(f);									
				free(fcontent);	
				j++;				
			}
        }
        closedir(pDIR);
    }
	int i=0;
	printf("\n");	
	if(strcmp(Order,"Account")==0){
	qsort(ThisPlayer,j,sizeof(struct Player),compareplayeraccount);
	}	
	for(i=0;i<j;i++){
		afisplayer(buffer,1,ThisPlayer,i);
		printf("\n");
	}
	free(ThisPlayer);
	printf("\n");
	system("pause");
}

static int compareaccountEmail (const void * a, const void * b){
	const struct Account *orderA= (struct Account *)a;
	const struct Account *orderB= (struct Account *)b;
	return strcmp(orderA->Email,orderB->Email);
}
static int compareaccountCharacter (const void * a, const void * b){
	const struct Account *orderA= (struct Account *)a;
	const struct Account *orderB= (struct Account *)b;
	return strcmp(orderA->Character,orderB->Character);
}
static int comparebonusName(const void * a, const void * b){
	const struct Bonus *orderA= (struct Bonus *)a;
	const struct Bonus *orderB= (struct Bonus *)b;
	return strcmp(orderA->Name,orderB->Name);
}
static int comparebonusTypeBonus(const void * a, const void * b){
	const struct Bonus *orderA= (struct Bonus *)a;
	const struct Bonus *orderB= (struct Bonus *)b;
	return  (orderA->TypeBonus)-(orderB->TypeBonus);
}
static int comparespellName (const void * a, const void * b){
	const struct Spell *orderA= (struct Spell *)a;
	const struct Spell *orderB= (struct Spell *)b;
	return strcmp(orderA->Name,orderB->Name);
}
static int comparespellTypeSpell (const void * a, const void * b){
	const struct Spell *orderA= (struct Spell *)a;
	const struct Spell *orderB= (struct Spell *)b;
	return (orderA->TypeSpell)-(orderB->TypeSpell);
}
static int compareitemName (const void * a, const void * b){
	const struct Item *orderA= (struct Item *)a;
	const struct Item *orderB= (struct Item *)b;
	return strcmp(orderA->Name,orderB->Name);
}
static int compareitemTypeItem (const void * a, const void * b){
	const struct Item *orderA= (struct Item *)a;
	const struct Item *orderB= (struct Item *)b;
	return (orderA->TypeItem)-(orderB->TypeItem);
}
static int compareplayeraccount (const void * a, const void * b){
	const struct Player *orderA= (struct Player *)a;
	const struct Player *orderB= (struct Player *)b;
	return strcmp(orderA->Account,orderB->Account);
}
