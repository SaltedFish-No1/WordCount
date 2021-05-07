#include<stdio.h>
#include<string.h>

#define MAX_SIZE 800 //字符数组大小，要求每行读取出字符串长度不超过800


int isPunctuationMark(char c);

//判断字符c是否为标点符号，是的话返回1，不是则返回0
int PassageAnalysis(char mode[MAX_SIZE], char path[MAX_SIZE]);

/*需要参数path：需要统计分析的txt文件路径
 * return 0：失败
 * return 1：成功
 *
 */

int main(int argc, char *argv[]) {
//    char mode[MAX_SIZE] = "-w";
//    char path[MAX_SIZE] = "..\\hamlet.txt";
//    PassageAnalysis(mode, path);
    if (argc == 3){
    PassageAnalysis(argv[1],argv[2]);
    }
    else
        printf("The number of arguments wrong!");
}

int PassageAnalysis(char mode[MAX_SIZE], char path[MAX_SIZE]) {
    char str[MAX_SIZE];
    FILE *fp;
    fp = fopen(path, "r"); //read only
    if (NULL == fp) {
        printf("Failed to open the file !\n");

        return 0;
    }
    //开始统计
    int characterNum = 0;
    int wordNum = 0;
    while (fgets(str, MAX_SIZE, fp) != NULL) {
/*         一行一行的统计，在单个的一行内，单词数 = 空格数+1
 *        由于文件编码为ASCII码，如果字符编码在 1~63、74~80、107到112、123~127范围内则统计为标点符号，否则为单词部分
 */
        wordNum++;//字符数为空格数加1
        int index = 0;
        while (str[index]) {
            if (isPunctuationMark(str[index]))
                characterNum++;
            if (int(str[index]) == 32)
                wordNum++;
            index++;
        }
//        fputs(str, stdout); //测试：把字符串输出到屏幕
    }
    if (strcmp(mode, "-c") * strcmp(mode, "-C") == 0)
        printf("The number of characters is: %d", characterNum);
    else if (strcmp(mode, "-w") * strcmp(mode, "-W") == 0)
        printf("The number of words is: %d", wordNum);
    fclose(fp);
    return 1;
}

int isPunctuationMark(char c) {
    if (c >= 1 && c <= 127)
        return 1;
    else
        return 0;
}

//改动后的注释