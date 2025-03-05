#include <stdio.h>

// 判断是否是闰年
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 获取某年某月的天数
int getDaysInMonth(int year, int month) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    return 31;
}

// 计算某年某月 1 日是星期几（0=周日，1=周一，...，6=周六）
int getDayOfWeek(int year, int month) {
    // 从 2007 年 1 月 1 日（星期一）开始计算
    int days = 0;
    for (int y = 2007; y < year; y++) {
        days += isLeapYear(y) ? 366 : 365;
    }
    for (int m = 1; m < month; m++) {
        days += getDaysInMonth(year, m);
    }
    return (days + 1) % 7; // 2007 年 1 月 1 日是星期一
}

// 打印日历
void printCalendar(int year, int month) {
    // 检查年份是否合法
    if (year < 2007) {
        printf("Invalid year. Year must be 2007 or later.\n");
        return;
    }

    // 打印表头
    printf("Calendar %04d - %02d\n", year, month);
    printf("---------------------\n");
    printf("Su Mo Tu We Th Fr Sa\n");
    printf("---------------------\n");

    // 获取该月 1 日是星期几
    int dayOfWeek = getDayOfWeek(year, month);

    // 打印开头的空格
    for (int i = 0; i < dayOfWeek; i++) {
        printf("   ");
    }

    // 打印日期
    int daysInMonth = getDaysInMonth(year, month);
    for (int day = 1; day <= daysInMonth; day++) {
        printf("%2d ", day);
        if ((day + dayOfWeek) % 7 == 0 || day == daysInMonth) {
            printf("\n");
        }
    }

    // 打印底部边框
    printf("---------------------\n");
}

int main() {
    int year, month;
    // 输入年份和月份
    scanf("%d %d", &year, &month);

    // 打印日历
    printCalendar(year, month);

    return 0;
}
