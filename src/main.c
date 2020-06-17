#include <stdio.h>
#include <locale.h>
#include <string.h>

#define ENG 26
#define RUS 32

void add_good() {
    printf("\nEnter text in file 'input.txt', and start program.\n");
}

void print_menu() {
    system("cls");  // очищаем экран
    printf("Menu\n");
    printf("1. Help\n");
    printf("2. Start program\n");
    printf(">");
}
int get_variant(int count) {
    int variant;
    char s[100]; // строка для считывания введённых данных
    scanf("%s", s); // считываем строку
    // пока ввод некорректен, сообщаем об этом и просим повторить его
    while (sscanf(s, "%d", &variant) != 1 || variant < 1 || variant > count) {
        printf("Unknown input data. Try again: "); // выводим сообщение об ошибке
        scanf("%s", s); // считываем строку повторно
    }
    return variant;
}


void encrypt (int n)//Шифровка цезаря
{
    FILE *fp1, *fp2;
    fopen_s(&fp1, "input.txt", "r");
    fopen_s(&fp2, "output.txt", "w");
    int flag;
    char c;
    c = getc(fp1);
    while (!feof(fp1))
    {
        flag = 0; //обработан ли текущий символ
        if (c >= 'A' && c <= 'Z')
        {
            c = c + (n % ENG);
            if (c > 'Z') c = 'A' + (c - 'Z') - 1;
            fprintf (fp2, "%c", c);
            flag = 1;
        }
        if (c >= 'a' && c <= 'z')
        {
            c = c + (n % ENG);
            if (c > 'z') c = 'a' + (c - 'z') - 1;
            fprintf (fp2, "%c", c);
            flag = 1;
        }
        if (c >= 'А' && c <= 'Я')
        {
            c = c + (n % RUS);
            if (c > 'Я') c = 'А' + (c - 'Я') - 1;
            fprintf (fp2, "%c", c);
            flag = 1;
        }
        if (c>='а' && c<='я')
        {
            c = c + (n % RUS);
            if (c > 'я') c = 'а' + (c - 'я') - 1;
            fprintf (fp2, "%c", c);
            flag = 1;
        }
        if (!flag) fprintf (fp2, "%c", c);
        c = getc(fp1);
    }
    fclose (fp1);
    fclose (fp2);
}

void decipher (int n)//Расшифровка цезаря
{
    FILE *fp1, *fp2;
    fopen_s(&fp1, "input.txt", "r");
    fopen_s(&fp2, "output.txt", "w");
    int flag;
    char c;
    c = getc(fp1);
    while (!feof(fp1))
    {
        flag = 0;
        if (c >= 'A' && c <= 'Z')
        {
            c = c - (n % ENG);
            if (c < 'A') c = 'Z' - ('A' - c) + 1;
            fprintf (fp2, "%c", c);
            flag = 1;
        }
        if (c >= 'a' && c <= 'z')
        {
            c = c - (n % ENG);
            if (c < 'a') c = 'z' - ('a' - c) + 1;
            fprintf (fp2, "%c", c);
            flag = 1;
        }
        if (c >= 'А' && c <= 'Я')
        {
            c = c - (n % RUS);
            if (c < 'А') c = 'Я' - ('А' - c) + 1;
            fprintf (fp2, "%c", c);
            flag = 1;
        }
        if (c >= 'а' && c <= 'я')
        {
            c = c - (n % RUS);
            if (c < 'а') c = 'я' - ('а' - c) + 1;
            fprintf (fp2, "%c", c);
            flag = 1;
        }
        if (!flag) fprintf (fp2, "%c", c);
        c = getc(fp1);
    }
    fclose (fp1);
    fclose (fp2);
}

char * encryptx(char * str)
{
	char * ret = str;
	
    while ( *str )
        --(*str++);
	
	return ret;
}

void encryptxor()
{
	FILE *fp1, *fp2;
    fopen_s(&fp1, "input.txt", "r");
    fopen_s(&fp2, "output.txt", "w");
	char buf[BUFSIZ];
	fscanf(fp1,"%[^\n]%*c",buf);
	fprintf(fp2, "%s", encryptx(buf));	
	fclose (fp1);
    fclose (fp2);
}

char * decryptx(char * str)
{
	char * ret = str;
	
    while ( *str )
        ++(*str++);
	
	return ret;
}

void decryptxor()
{
	FILE *fp1, *fp2;
    fopen_s(&fp1, "input.txt", "r");
    fopen_s(&fp2, "output.txt", "w");
	char buf[BUFSIZ];
	fscanf(fp1,"%[^\n]%*c",buf);
	fprintf(fp2, "%s", decryptx(buf));	
	fclose (fp1);
    fclose (fp2);
}

int main (int argc, char *argv[])
{
	int n;
	int a;
	setlocale(LC_ALL,"Rus");
	int variant; // выбранный пункт меню
    int size = 0; // количество элементов массива товаров
    int capacity = 1; // ёмкость массива товаров
    do {
        print_menu(); // выводим меню на экран
        variant = get_variant(2); // получаем номер выбранного пункта меню
        switch (variant) {
            case 1:
                add_good();
                break;
        }
        if (variant != 2)
            system("pause"); // задерживаем выполнение, чтобы пользователь мог увидеть результат выполнения выбранного пункта
    }while (variant != 2);
	
	printf ("Enter '1' for xor encrypt.\nEnter '2' for xor decipher.\nEnter '3' for cez encrypt.\nEnter '4' for cez decipher.\n");
	printf("You entering:");
	scanf_s ("%d", &a);
	getchar ();
	system("cls");
	switch(a){
	//Шифровка в XOR
	case 1:
		encryptxor();
		printf("Encrypt done! Scan files output.txt\n");
    
	break;	
	
	//Дешифровка XOR
	case 2:
		decryptxor();
		printf("Encrypt done! Scan files output.txt\n");
	break;	
	
	//Шифровка в Цезаря
	case 3:
		printf ("Enter natural n: ");
		scanf_s ("%d", &n);
		getchar (); //нужен для того, чтобы поймать символ клавиши ENTER, нажатой при вводе числа n
		if (n < 1) return 0;
		encrypt (n);
		printf("Encrypt done! Scan files output.txt\n");
	break;	
	
	//Дешифровка Цезаря
	case 4:
		printf ("Enter natural n: ");
		scanf_s ("%d", &n);
		getchar (); //нужен для того, чтобы поймать символ клавиши ENTER, нажатой при вводе числа n
		if (n < 1) return 0;
		decipher (n);
		printf("Decipher done! Scan files output.txt\n");
	break;
}	
	system("pause");
    return 0;
}
