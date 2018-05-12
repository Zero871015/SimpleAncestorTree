# SimpleAncestorTree

血緣關係 

針對家族成員和成員間血緣關係的家族族譜，0 是 7 的孩子，1、2 和 3 是 0 的孩子，4 和 5 是 1 的孩子，6 是 3 的孩 子。最遠的親戚關係為 4(或 5)和 6，其"血緣距離"是 4 (4~1，1~0， 0~3，3~6)。 
給予任一家族的關係圖，請找出所有成員的 "血緣距離"。 
假設只有一個人是整個家族成員的祖先，而且沒有兩個成員有同樣的小孩。 

7 
| 
0--------- 
| | | 
1 2 3----6 
|---- 
| | 
4 5 

輸入格式 
第一行為一正整數 n 代表成員個數，每人以 0~n-1 間惟一編號代表。接著n-1 行，每行有兩個以一個空白隔開的整數 a 與 b (0 ? a, b ? n-1)，代表 b 是 a 的 孩子。 

輸出格式 
輸出所有成員"血緣距離"。 

範例： 

輸入 
8 
0 1 
0 2 
0 3 
7 0 
1 4 
1 5 
3 6 

輸出 
0-1-1 
0-2-1 
0-3-1 
0-4-2 
0-5-2 
0-6-2 
0-7-1 
1-2-2 
1-3-2 
1-4-1 
1-5-1 
1-6-3 
1-7-2 
2-3-2 
2-4-3 
2-5-3 
2-6-3 
2-7-2 
3-4-3 
3-5-3 
3-6-1 
3-7-2 
4-5-2 
4-6-4 
4-7-3 
5-6-4 
5-7-3 
6-7-3
