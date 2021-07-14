//
//  kujibiki.c
//  prg1
//
//  Created by k20076kk on 2020/07/31.
//

#include <stdio.h>
#include <stdlib.h>//乱数を使うため
#include <unistd.h>//sleep関数を使うため
#include <time.h>//乱数初期化を行うため
int garagara(){
    
    double delay = 1.5; //タイマ用
    
    srand((unsigned int)time(NULL));//乱数の初期化処理
    
    printf("ガラガラ...");
    printf("ガラガラ...\n");
    sleep(delay);//抽選を再現するためのディレイ。今回は1.5秒に設定。
    printf("ポトッ！\n");
    sleep(delay);//同上
    
    int result = rand() % 100 + 1;//結果は乱数で1-100までで判定
    
    return(result);//結果をmain関数に返す
}

int main(int argc, const char * argv[]){
    
    int ans, res, gara, ticket=10;//ansは選択,resは結果,garaはガラガラの結果,ticketは福引券の枚数
    /*券の枚数はticketの値を変えれば変更可能**/
    int atari1, atari2, atari3, atari4, hazure;//抽選結果によって個別に加算する
    double delay = 1.5;//タイマ用
    
    printf("福引会場へようこそ！\n");
    printf("プログラムを実行してくれたお礼に福引券を%d枚プレゼントします！\n", ticket);
    //あいさつを表示
    while(ticket>=0){//チケットがなくなって処理を行うまで実行
        printf("残りの福引券の枚数 = %d\n", ticket);//残り枚数
        printf("どうしますか？ 1.福引を回す 2.帰る　3.これは何?　:  ");
        scanf("%d", &ans);//ここで選択
        
        switch(ans){//選択したものに応じて処理を実行
                
            case 1:
                if(ticket>0){
                    ticket--;//券を消費させる
                    res = garagara();//ここは自作関数、garagaraの結果をresとする
                    if(res>=95){//95以上の場合は1等と表示
                        printf("おめでとうございます！1等が当選しました！\n");
                        printf("乱数:%d\n", res);
                        atari1++;
                    }
                    else if(res>=85&&res<95){//85以上95未満の時は2等と表示
                        printf("おめでとうございます！2等が当選しました！\n");
                        printf("乱数:%d\n", res);
                        atari2++;
                    }
                    else if(res>=70&&res<85){//70以上85未満の時は3等と表示
                        printf("おめでとうございます！3等が当選しました！\n");
                        printf("乱数:%d\n", res);
                        atari3++;
                    }
                    else if(res>=50&&res<70){//50以上70未満の時は4等と表示
                        printf("おめでとうございます！4等が当選しました！\n");
                        printf("乱数:%d\n", res);
                        atari4++;
                    }
                    else{
                        printf("残念...ハズレです...\n");//それ未満の時はハズレと表示
                        printf("乱数:%d\n", res);
                        hazure++;
                    }
                }
                else{
                    ticket--;//ループを抜け出す処理
                    printf("では福引を...");
                    printf("おや? あなたは福引券を持ってないようですね...\n");
                    sleep(delay);
                    break;
                }
                break;
            case 2:
                ticket = -1;//ループを抜け出す処理
                break;
                
            case 3:
                printf("\n商店街やお祭りでよくあるガラポン抽選を再現してみました。\n");
                printf("抽選は1-100の乱数で行います。数字の範囲で結果が決まります。\n");
                printf("\n");
                /*ここでプログラムについて簡単に説明,見えやすくするために上下に改行を加えた。**/
                break;
                
            default:
                printf("正しい数字を入力してください！\n");//指定された数字以外が入力されたらエラーを表示
                break;
        }
    }
    printf("ありがとうございました。\n");
    printf("\n");
    printf("結果: 1等 %d 回　2等 %d 回 3等 %d 回 4等 %d 回 ハズレ %d 回\n", atari1, atari2, atari3, atari4, hazure);//抽選結果の合計を表示。
    
    return 0;
}
