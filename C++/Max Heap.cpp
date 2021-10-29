#include <iostream>
#include <cstring>
#define MAX_ELEMENTS 200
using namespace std;
int heap[MAX_ELEMENTS];
int num; 
void printHeap(){
    int i;
    if (num == 0)
 		cout << "Heap是空的 " << endl;
    for (i = 1; i <= num; i++)		
 		cout << "欄位 "<< i << " 為 " << heap[i] << endl;
}
void insert(int val){  
    int i; 	/* 最後一個位子 */
	
    if (num >= MAX_ELEMENTS) 
         cout << "Heap滿了 " << endl; 
		
    i= ++num;	/* 讓樹根為heap[1] */

    /* 確定樹有值,要加入的數小於它的parent */
    while ((i != 1) && (val > heap[i/2]))	
    {
        heap[i] = heap[i / 2];	/* parent的值下移到空位 */
        i /= 2;			/* parent上移 */
    }

    /* 樹為空或要加入的數大於它的parent，直接放入heap */
    heap[i] = val; 		
}
void deleteMax(){
    int parent, child, temp;
	
    if (num == 0){		
 		cout << "Heap是空的 " << endl;
		return;
    }

    temp = heap[num--];		/* 令temp為heap的最後一個數 */

    parent = 1;
    child = 2;
    cout << "刪除 " <<heap[parent] << endl;

    while (child <= num)		
    {
        /* 不是最後一個數 且 左子樹>右子樹 */
        if ((child < num) && (heap[child]) < heap[child + 1])
            child++;		/* 選擇右子樹*/

        /* 如果最後一個數較小 跳出while迴圈 */
        if (temp >= heap[child]) 
            break;
		   heap[parent] = heap[child];     /* child的值放到parent指的位子 */
        parent = child;		       /* 原本的child變parent */
        child *= 2;		       /* 新的child下移 */
    }
    /* 最後一個數為樹的最大值，直接放到樹根 */
    heap[parent] = temp;	
}

int main(){
    int input,val;
    int num = 0;	
		
    do{
    	system("cls");	      /* 清空畫面 */

        cout << endl; 
        cout << "這是一個最小堆積的程式:" << endl; 
        cout << "(1)新增一個值<insert>" << endl; 
        cout << "(2)刪除最大值<deleteMax>" << endl; 
        cout << "(3)列印整個堆積<printHeap>" << endl; 
        cout << "(4)離開程式<Exit>" << endl; 
        cout << "輸入要執行的選項:" ; 
    cin >> input;
    cout << endl;

    switch (input)	{
        case 1:	
	    	cout << "輸入0以終止" << endl; 				
	    do{
			cout << " 輸入新增的值: ";
            cin >> val; 					
				if(val!=0)
		    		insert(val);		
		}while(val!=0);
				
		system("PAUSE");
		break;	
		case 2:			
		deleteMax();   	  
		cout << endl;
		system("PAUSE");
		break;	
	
		case 3:			
		printHeap();
		cout << endl; 
		system("PAUSE");
		break;

		case 4:		
		break;	

		default:	
		cout << " 請輸入1-4的數字 " << endl;
		system("PAUSE");
	}
    } while (input != 4);

    system("PAUSE");
    return 0;
}	

