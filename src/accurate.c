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
    char head[99], last[99];
    char list[99][10];
    FILE *fp;
    int i = 0, a;
    printf("————精准匹配模式启动（只匹配前后字符相同的成语，拼音相同不再作为条件）————\n");
    srand((unsigned)time(NULL));
    while (1){
        i = 0;
        printf("请输入成语(四字)：\n");
        scanf("%s", buf);
        if (buf[0] == '#') break;
        if (strlen(buf) != 8) {
            printf("你输入的不是四字成语哦。\n\n");
            continue;
        }
        char2spell(buf, spell);
        sprintf(path, "list/%s.txt", spell);
        strcpy(last, buf + 6);
//        if (access(path, F_OK) != 0){
//            printf("无法找到匹配的成语。\n");
//            continue;
//        }

        fp = fopen(path, "r");
        while(feof(fp) == 0){
            fscanf(fp, "%s", buf2);
            sprintf(head, "%.2s", buf2);
            if (strcmp(head, last) == 0){
                strcpy(list[i], buf2);
                i++;
            }
        }
        if (i == 0){
            printf("无法找到匹配的成语。\n\n");
            continue;
        }
        a = rand()%i;
        printf("找到%d个候选，选择第%d个。\n", i + 1, a + 1);
        rewind(fp);
//        for (int j = 0; j < a; ++j) {
//            fscanf(fp, "%s", buf2);
//        }

        printf("接：%s\n\n", list[a]);
        fclose(fp);
    }
    return 0;
}