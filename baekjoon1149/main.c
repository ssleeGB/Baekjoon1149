//
//  main.c
//  baekjoon1149
//
//  Created by 이승섭 on 2018. 12. 13..
//  Copyright © 2018년 이승섭. All rights reserved.
//

#include <stdio.h>

int main(void) {
    
    int N, i, j;
    int house;
    int cost[1000][1000];
    int min;
    int color = 0; // 0 : Red, 1 : Green, 2 : Blue
    int sum = 0;
    
    FILE *fp = fopen("input.txt","r");
    
    fscanf(fp, "%d", &N);
    printf("%d\n", N);
    
    if(N <= 1000)
    {
        for(i = 0; i < N; i++)
        {
            for(j = 0; j < N; j++)
            {
                fscanf(fp, "%d", &house);
                cost[i][j] = house;
                printf("%d ", cost[i][j]);
            }
            printf("\n");
        }
        
        for(i = 0; i < N; i++)
        {
            for(j = 0, min = cost[i][j]; j < N; j++)
            {
                if(cost[i][j] < min)
                {
                    min = cost[i][j];
                    color = j;
                }
            }
            cost[i+1][color] = 1001;
            printf("%d \n", min);
            printf("Color index : %d \n", color);
            color = 0;
            sum += min;
            printf("Total cost : %d \n", sum);
        }
    }

    fclose(fp);
    
    return 0;
}
