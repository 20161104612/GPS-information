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
FILE *fp1;
FILE *fp3;
int main()
{
    void GPRMC(int n);
    void GPGGA(int n);
    int i=0,len;
    FILE *GPSDATAS = fopen("//Users//a20161104612//Desktop//GPS//GPSDATAS.TXT","r");
    

    if(GPSDATAS==NULL)
    {
        printf("打开文件夹失败!\n");
    }
    for(;(GPSDATA[i++]=fgetc(GPSDATAS))!=EOF;)
        putchar(GPSDATA[i-1]);
    len=i;
    for(i=0;i<len;i++)
    {
        if(GPSDATA[i]=='G'&&GPSDATA[i+1]=='G'&&GPSDATA[i+2]=='A')
            GPGGA(i+3);
        if(GPSDATA[i]=='R'&&GPSDATA[i+1]=='M'&&GPSDATA[i+2]=='C')
            GPRMC(i+3);
    }
    fclose(GPSDATAS);
}

void GPRMC(int n)
{
    int i,j,k;
    char *p=GPSDATA;
    char ch[14][14]={'\0'};
    char hour[5]={'\0'};              /*定义小时*/
    char min[5]={'\0'};               /*定义分钟*/
    char sec[10]={'\0'};               /*定义秒钟*/
    char dingwei[10]={'\0'};           /*定义定位状态 A=有效定位，V=无效定位*/
    char wdu[10]={'\0'},wfen[10]={'\0'};      /*定义纬度和分*/
    char jdu[10]={'\0'},jfen[10]={'\0'};      /*定义经度和分*/
    char suli[10]={'\0'};              /*定义地面速率*/
    char hangxiang[8]={'\0'};         /*定义地面航向*/
    char year[10]={'\0'};char month[10]={'\0'};char date[10]={'\0'};/*定义UTC日期，ddmmyy(日月年)格式*/
    char cipian[10]={'\0'};            /*定义磁偏角，前面的0也将被传输*/
    char fangxiang[10]={'\0'};         /*定义磁偏角方向*/
    char mode[10]={'\0'};              /*模式指示(仅NMEA01833.00版本输出，A=自主定位，D=差分，E=估算，N=数据无效)*/
    char dongxi[10],nanbei[10]={'\0'}; /*定义东西经度，南北纬*/
    for(k=0;k<14;k++)
    {
        for(n=n+1,j=0;n<500;n++)
            if(GPSDATA[n]!=',')
            {
                ch[k][j]=*(p+n);
                j++;
            }
        else
            break;
    }
    for(j=0,i=0;j<2;j++,i++)
        hour[j]=ch[0][i];
    for(j=0;j<2;i++,j++)
        min[j]=ch[0][i];
    for(j=0;j<5;j++,i++)
        sec[j]=ch[0][i];
    for(j=0,i=0;j<2;j++,i++)
        date[j]=ch[8][i];
    for(j=0;j<2;j++,i++)
        month[j]=ch[8][i];
    for(j=0;j<2;j++,i++)
        year[j]=ch[8][i];
    for(i=0,j=0;j<2;i++,j++)
        wdu[j]=ch[2][i];
    for(j=0;j<8;j++,i++)
        wfen[j]=ch[2][i];
    for(i=0,j=0;j<2;j++,i++)
        jdu[j]=ch[4][i];
    for(j=0;j<8;i++,j++)
        jfen[j]=ch[4][i];
    for(i=j=0;j<8;i++,j++)
        nanbei[j]=ch[3][i];
    for(i=j=0;j<8;i++,j++)
        dongxi[j]=ch[5][i];
    if((int)(ch[1][0])=='A')
        strcpy(dingwei,"use");
    else if((int)(ch[1][0])=='V')
        strcpy(dingwei,"useless");
    for(i=j=0;j<8;i++,j++)
        suli[j]=ch[6][i];
    for(i=j=0;j<8;i++,j++)
        hangxiang[j]=ch[7][i];
    for(i=j=0;j<4;i++,j++)
        cipian[j]=ch[9][i];
    for(i=j=0;j<8;i++,j++)
        fangxiang[j]=ch[10][i];
    for(i=j=0;j<8;i++,j++)
        mode[j]=ch[11][i];
    fp1=fopen("//Users//a20161104612//Desktop//GPS//fp1.txt","a+");
    fp3=fopen("//Users//a20161104612//Desktop//GPS//fp3.csv","a+");
    fprintf(fp1,"\n日期:%s-%s-%s\n时间:%s时%s分%s秒\n定位情况:%s\n纬度:%s纬 %s度%s分\n经度:%s经 %s度%s分\n地面速率:%s\n地面航向:%s\n磁偏角:%s\n度磁偏角方向:%s",year,month,date,hour,min,sec,dingwei,nanbei,wdu,wfen,dongxi,jdu,jfen,suli,hangxiang,cipian,fangxiang);
    fprintf(fp3,"\n日期:%s-%s-%s时间:%s时%s分%s秒定位情况:%s纬度:%s纬 %s度%s分经度:%s经 %s度%s分地面速率:%s地面航向:%s磁偏角:%s度磁偏角方向:%s",year,month,date,hour,min,sec,dingwei,nanbei,wdu,wfen,dongxi,jdu,jfen,suli,hangxiang,cipian,fangxiang);
    fclose(fp1);
    fclose(fp3);
    printf("\n日期:%s-%s-%s\n时间:%s时%s分%s秒\n定位情况:%s\n纬度:%s纬 %s度%s分\n经度:%s经 %s度%s分\n地面速率:%s\n地面航向:%s\n磁偏角:%s\n度磁偏角方向:%s",year,month,date,hour,min,sec,dingwei,nanbei,wdu,wfen,dongxi,jdu,jfen,suli,hangxiang,cipian,fangxiang);
    
}


void GPGGA(int n)
{
    int i,j,k;
    char *p=GPSDATA;
    char ch[140][140]={'\0'};
    char chhour[5]={'\0'};              /*定义小时*/
    char chmin[5]={'\0'};               /*定义分钟*/
    char chsec[8]={'\0'};               /*定义秒钟*/
    char wdu[10]={'\0'},wfen[10]={'\0'};      /*定义纬度和分*/
    char jdu[10]={'\0'},jfen[10]={'\0'};      /*定义经度和分*/
    char dingwei[14]={'\0'};           /*质量因子 1=实时GPS,2=差分GPS*/
    char weixingsu[8]={'\0'};        /*可使用卫星数*/
    char suiping[8]={'\0'};           /*水平精度因子*/
    char tianxian[10]={'\0'};          /*天线高程*/
    char haiba[10]={'\0'};             /*大地椭球面相对海平面的高度*/
    char gpsage[8]={'\0'};            /*差分GPS年龄，实时GPS无*/
    char gpsnumber[8]={'\0'};         /*差分基准站号*/
    char dongxi[10]={'\0'},nanbei[10]={'\0'}; /*定义东西经度，南北纬*/
    for(k=0;k<14;k++)
    {
        for(n=n+1,j=0;n<500;n++)
        {
            if(GPSDATA[n]!=',')
            {
                ch[k][j]=*(p+n);
                j++;
            }
            else
                break;
        }
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
        if((int)(ch[5][0])==48)
           strcpy(dingwei,"没有定位");
        else if((int)(ch[5][0])==49)
            strcpy(dingwei,"实时GPS");
        else if((int)(ch[5][0])==50)
            strcpy(dingwei,"差分GPS");
        for(i=j=0;j<8;i++,j++)
            weixingsu[j]=ch[6][i];
        for(i=j=0;j<8;i++,j++)
            suiping[j]=ch[7][i];
        for(i=j=0;j<8;i++,j++)
            tianxian[j]=ch[8][i];
        for(i=j=0;j<8;i++,j++)
            haiba[j]=ch[10][i];
        for(i=j=0;j<8;i++,j++)
            gpsage[j]=ch[12][i];
        for(i=j=0;j<3;i++,j++)
            gpsnumber[j]=ch[13][i];
    fp1=fopen("//Users//a20161104612//Desktop//GPS//fp1.txt","a+");
    fp3=fopen("//Users//a20161104612//Desktop//GPS//fp3.csv","a+");
    fprintf(fp1,"时间:%s时%s分%s秒\n纬度:%s纬 %s度%s分\n经度:%s经 %s度%s分\n定位情况:%s\n可使用卫星数:%s颗\n水平精度因子:%s\n天线高程:%s米\n海拔:%s米\nGPS年龄:%s\n差分基准站:%s\n",chhour,chmin,chsec,nanbei,wdu,wfen,dongxi,jdu,jfen,dingwei,weixingsu,suiping,tianxian,haiba,gpsage,gpsnumber);
    fprintf(fp3,"时间:%s时%s分%s秒纬度:%s纬 %s度%s分经度:%s经 %s度%s分定位情况:%s可使用卫星数:%s颗水平精度因子:%s天线高程:%s米海拔:%s米GPS年龄:%s差分基准站:%s\n",chhour,chmin,chsec,nanbei,wdu,wfen,dongxi,jdu,jfen,dingwei,weixingsu,suiping,tianxian,haiba,gpsage,gpsnumber);
    fclose(fp1);
    fclose(fp3);
    printf("时间:%s时%s分%s秒\n纬度:%s纬 %s度%s分\n经度:%s经 %s度%s分\n定位情况:%s\n可使用卫星数:%s颗\n水平精度因子:%s\n天线高程:%s米\n海拔:%s米\nGPS年龄:%s\n差分基准站:%s\n",chhour,chmin,chsec,nanbei,wdu,wfen,dongxi,jdu,jfen,dingwei,weixingsu,suiping,tianxian,haiba,gpsage,gpsnumber);
    
}
