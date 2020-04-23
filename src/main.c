#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


void char2spell(const char s[], char d[]){
    FILE *fp1, *fp2;
    char spell[100];
    fp1 = fopen("in.dat", "w+");
    fprintf(fp1, "%.2s\n", s+6);
    fclose(fp1);
    system("Char2spell.exe");
    fp2 = fopen("out.dat", "r");
    fscanf(fp2, "%s", spell);
    strcpy(d, spell);
    fclose(fp2);
}

int main() {
    char buf[100], spell[100], path[100], buf2[100];
    FILE *fp;
    int i = 0, a;
    while (1){
        srand((unsigned)time(NULL));
        i = 0;
        printf("请输入成语(四字)：");
        scanf("%s", buf);
        if (buf[0] == '#') break;
        char2spell(buf, spell);
        sprintf(path, "list/%s.txt", spell);
        if (access(path, F_OK) != 0){
            printf("无法找到匹配的成语。\n");
            continue;
        }

        fp = fopen(path, "r");
        while(feof(fp) == 0){
            fscanf(fp, "%s", buf2);
            i++;
        }

        a = rand()%i;
        printf("找到%d个候选，选择第%d个。\n", i, a);
        rewind(fp);
        for (int j = 0; j < a; ++j) {
            fscanf(fp, "%s", buf2);
        }
        printf("接：%s\n\n", buf2);
        fclose(fp);
    }
    return 0;
}