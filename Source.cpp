#include "stdafx.h"

using namespace std;

//cvicenie 2 

//ULOHA 1 
long pocitaj(long a, long b) {
	__asm {
		mov eax, a
		mov ebx, b
		add eax, b
		add eax, eax
	}
}

//Uloha 2

unsigned short zloz(unsigned char x, unsigned char y) {
	__asm {
		mov ah, x
		mov al, y
		xchg ah, al
	}
}

//Uloha 3

long pocitaj2(long m, long n) {
	__asm {
		mov eax, 12     //cim chcem vynasobit
		mov edx, 17     //cim chcem vynasobit
		mov ecx, m      //co chcem vynasobit
		mov ebx, n       //co chcem vynasobit
		imul eax, ecx   //vynasobim eax * ecx
		imul edx, ebx  //vynasobim edx * ebx
		add eax, edx   // zratam  

	}
}

// Uloha 4

unsigned long prehod(unsigned long x) {
	__asm {
		mov eax, x
		rol eax, 16
	}
}

//Cvicenie 3

//Uloha 1
long vacsie(long x, long y) {
	__asm {
		mov eax, x
		cmp eax, y
		jae a1
		mov eax, y
	a1:
	}
}

//Uloha 2
unsigned long vacsie2(unsigned long x, unsigned long y) {
	__asm {
		mov eax, x
		cmp eax, y
		jge a1
		mov eax, y
	a1:
	}
}

//Uloha 3 

unsigned char ntybitx(unsigned char n, unsigned long x) {
	__asm {
		mov eax, x
		mov cl, n
		shr eax, cl
		and ax, 1 
	}
}
// Uloha 4

bool obsahuje(unsigned long hodnota, unsigned char vzorka) {
	__asm {
		mov ecx, 25
		mov eax, 0
		mov ebx, hodnota
		mov dl, vzorka
	a1:	cmp bl, dl
		je rovne
		ror ebx, 1
		loop a1
	jmp kon
	rovne: add eax, 1
		   loop a1
	kon: 
	}
}

//Uloha 5

unsigned short zips(unsigned char x, unsigned char y) {
	__asm {
		mov bl, x
		mov dl, y 
		mov ecx, 8
	a1 : rol bl, 1 
		rcl eax, 1
		rol dl, 1
		rcl eax, 1
		loop a1
	a2: 

	}
}

//Uloha 6 

unsigned short rozober1(unsigned long x) {
	__asm {
		mov eax, 0 
		mov ebx, x
		mov ecx, 15
		rol ebx, 1
		rcl ax, 1
	a1: rol ebx, 2
		rcl ax, 1
		loop a1
	}
}

// Cvicenie 4

//Uloha 1

long kolkokrat(long x[], long n, long p) {
	__asm {
		mov eax, 0
		mov ecx, n 
		mov ebx, x
		mov edx, p
		jecxz a3
	a1: cmp edx, [ebx]
		jne a2
		add eax, 1
	a2: add ebx, 4
		loop a1
	a3:
		
	}
}

// Uloha 2

long kolkokrat_r(char *x, char p) {
	__asm {
		mov eax, 0
		mov ebx, x
		mov cl, p
		a1 : cmp cl, [ebx]
			 jne a2
			 add eax, 1
		a2 : add ebx, 1
			 mov ch, [ebx]
			 cmp ch, 0
			 jne a1
		a3 :
	}
}

// Uloha 3

long nahrad(char *x, char p, char q) {
	__asm {
		mov eax, 0
		mov ebx, x
		mov cl, p
		mov dl, q
   a1 : cmp cl, [ebx]
		jne a2
		mov [ebx], dl
		add eax, 1
   a2 : add ebx, 1
		mov ch, [ebx]
		cmp ch, 0
		jne a1
   a3 :
	}
}

// Uloha 4

/*unsigned long ktore(char *x, char p) {
	__asm {
		mov ebx, x
		mov eax, 0
		mov ecx, 32
		mov dl, p
   a1 : cmp dl, [ebx]
		jne a2
		mov [ecx + eax*4], [ebx]
   a2 : jecxz a3
		add ebx, 4
		loop a1
	a3:
	}
}*/

// Civcenie 5

// Uloha 1
char z(unsigned char b) {
	__asm {
		mov al, 0
		mov bl, b
		mov ecx, 8
	a1: shr bl, 1
		jc a2
		inc al
		jmp a3
	a2 : dec al
	a3 : loop a1
	}
}

// Uloha 2

void zips_poli(long x[], long y[], long n, long vysledok[]) {
	__asm {
		mov eax, vysledok
		mov ecx, n
		mov ebx, x
		mov edx, y
		jecxz a3
   a1 : mov esi, [ebx]
		mov[eax], esi
		add eax, 4
		add ebx, 4
		mov esi, [edx]
		mov[eax], esi
		add eax, 4
		add edx, 4
		loop a1
	  a3 :
	}
}


// main
int main(){
	long a = 10;
	long b = 5;
	char x = 10;
	char y = 11;
	long m = 10;
	long n = 10;
	long pole[] = { 1,1,5,3,4,5,67,5,8,9,10 };
	char ret[] = "abcdaaa";
	printf("<-------------------------Cvicenie 2------------------------------>\n");
	printf("\tUloha 1: Funkcia pocitaj:\t%d\n",pocitaj(a, b));
	printf("\tUloha 2: Funkcia zloz:\t%x\n", zloz(x, y));
	printf("\tUloha 3: Funkcia pocitaj2:\t %d\n", pocitaj2(m,n));
	printf("\tUloha 4: Funkcia prehod:\t %x \n", prehod(15));

	printf("<-------------------------Cvicenie 3------------------------------>\n");
	printf("\tUloha 1: Funkcia vacsie:\t %d \n", vacsie(10, 1));
	printf("\tUloha 2: Funkcia vacsie2:\t %d \n", vacsie2(-10, -1));
	printf("\tUloha 3: Funkcia ntybitx:\t %d \n", ntybitx(1,10));
	printf("\tUloha 4: Funkcia obsahuje:\t %x \n", obsahuje(0xfcaaaaaa, 0x7e));
	printf("\tUloha 5: Funkcia zips:\t %d \n", zips(5, 6));
	printf("\tUloha 6: Funkcia rozober1:\t %d \n", rozober1(10));

	printf("<-------------------------Cvicenie 4------------------------------>\n");
	printf("\tUloha 1: Funkcia kolkokrat:\t %d \n", kolkokrat(pole, 10, 1));
	printf("\tUloha 2: Funkcia kolkokrat_r:\t %d \n", kolkokrat_r("ababbcd", 'b'));
	printf("\tUloha 3: Funkcia nahrad:\t %d \n", kolkokrat_r("ababbcd", 'b'));
	//printf("\tUloha 4: Funkcia ktore:\t %d %s\n \n", ktore("abacdab", 'b'));

	printf("<-------------------------Cvicenie 5------------------------------>\n");
	printf("\tUloha 1: Funkcia z:\t %d \n", z(0xFE));
	long l[] = { 1,2,3,4,5,6,7,8,9,10 };
	long k[] = { 10,90,80,70,60,50,40,30,20,10 };
	long vysledok[20];
	long *u = l;
	long *t = k;
	long *s = vysledok;
	zips_poli(u, t, 10, s);
	printf("\t");
	for (int i = 0; i < 20; i++) {
		printf("%d ", vysledok[i]);
	}
	getchar();
	return 0;
}