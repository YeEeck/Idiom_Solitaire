#include <stdio.h>
#include <string.h>
#include <windows.h>


int main() {
    FILE *fp1, *fp2, *fp3, *fp4;
    char temp[10000], t, path[1000], spell[100];
    int i = 0;
    fp1 = fopen("data/idiom_re.txt", "r");

    while (feof(fp1) == 0){
        fscanf(fp1, "%s", temp);
        if (strlen(temp) != 8){
            continue;
        }
        fp2 = fopen("in.dat", "w+");
        fprintf(fp2, "%.2s\n", temp);
        //fprintf(fp2, "%s\n", temp);
        fclose(fp2);
        system("Char2spell.exe");
        //Sleep(100);
        fp4 = fopen("out.dat", "r");
        fscanf(fp4, "%s", spell);
        system("cls");
        printf("已导入%d条成语", ++i);
        sprintf(path, "data/list/%s.txt", spell);
        fp3 = fopen(path, "a");
        fprintf(fp3, "%s\n", temp);
        fclose(fp3);fclose(fp4);
    }

    return 0;
}