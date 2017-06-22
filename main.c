//
//  main.c
//  GPS information
//
//  Created by 20161104612 on 2017/6/16.
//  Copyright © 2017年 20161104612. All rights reserved.
//

#include <stdio.h>
#include <string.h>
char GPSDATA[500];


int main()
{
    void GPRMC();
    void GPGGA();
    FILE *GPSDATA = fopen("//Users//a20161104612//Desktop//GPS//GPSDATA.TXT","r+");
    FILE *GPSDATAS = fopen("//Users//a20161104612//Desktop//GPS//GPSDATAS.TXT","w");
    if(GPSDATA==NULL)
    {
        printf("打开文件夹失败!\n");
    }
    else
    {
        return 0;
    }
}

void GPRMC()
{
    int i,j,k,n;
    char*p=GPSDATA;
    char hour[10];              /*定义小时*/
    char min[10];               /*定义分钟*/
    char sec[10];               /*定义秒钟*/
    char dingwei[15];           /*定义定位状态 A=有效定位，V=无效定位*/
    char wdu[10],wfen[10];      /*定义纬度和分*/
    char jdu[10],jfen[10];      /*定义经度和分*/
    char suli[10];              /*定义地面速率*/
    char hangxiang[10];         /*定义地面航向*/
    char year[10];char month[10];char date[10];/*定义UTC日期，ddmmyy(日月年)格式*/
    char cipian[10];            /*定义磁偏角，前面的0也将被传输*/
    char fangxiang[10];         /*定义磁偏角方向*/
    char mode[10];              /*模式指示(仅NMEA01833.00版本输出，A=自主定位，D=差分，E=估算，N=数据无效)*/
    char dongxi[10],nanbei[10]; /*定义东西经度，南北纬*/
}

void GPGGA()
{
    int i,j,k,n;
    char *p=GPSDATA;
    char ch[14][14];
    char chhour[5];              /*定义小时*/
    char chmin[5];               /*定义分钟*/
    char chsec[8];               /*定义秒钟*/
    char wdu[10],wfen[10];      /*定义纬度和分*/
    char jdu[10],jfen[10];      /*定义经度和分*/
    char dingwei[14];           /*质量因子 1=实时GPS,2=差分GPS*/
    char weixingshu[8];        /*可使用卫星数*/
    char suiping[8];           /*水平精度因子*/
    char tianxian[10];          /*天线高程*/
    char haiba[10];             /*大地椭球面相对海平面的高度*/
    char gpsage[8];            /*差分GPS年龄，实时GPS无*/
    char gpsnumber[8];         /*差分基准站号*/
    char dongxi[10],nanbei[10]; /*定义东西经度，南北纬*/
    for(k=0;k<14;k++)
    {
        for(n=n+1,j=0;n<500;n++)
        {
            if(GPSDATA[n]!=0)
            {
                ch[k][j]=*(p+n);
                j++;
            }
            else
                break;
        }
        for(j=0,i=0;j<2;j++,i++)
            chhour[j]=ch[0][i];
        for(j=0;j<2;j++,i++)
            chmin[j]=ch[0][i];
        for(j=0;j<5;i++,j++)
            chsec[j]=ch[0][i];
        for(j=0,i=0;j<2;j++,i++)
            wdu[j]=ch[1][i];
        for(j=0;j<8;i++,j++)
            wfen[j]=ch[1][i];
        for(j=0,i=0;j<2;j++,i++)
            jdu[j]=ch[3][i];
        for(j=0;j<8;i++,j++)
            jfen[j]=ch[3][i];
        for(i=j=0;j<8;i++,j++)
            nanbei[j]=ch[2][i];
        for(i=j=0;j<8;i++,j++)
            dongxi[j]=ch[4][i];
    }
}
