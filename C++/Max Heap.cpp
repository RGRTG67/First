#include <iostream>
#include <cstring>
#define MAX_ELEMENTS 200
using namespace std;
int heap[MAX_ELEMENTS];
int num; 
void printHeap(){
    int i;
    if (num == 0)
 		cout << "Heap�O�Ū� " << endl;
    for (i = 1; i <= num; i++)		
 		cout << "��� "<< i << " �� " << heap[i] << endl;
}
void insert(int val){  
    int i; 	/* �̫�@�Ӧ�l */
	
    if (num >= MAX_ELEMENTS) 
         cout << "Heap���F " << endl; 
		
    i= ++num;	/* ����ڬ�heap[1] */

    /* �T�w�𦳭�,�n�[�J���Ƥp�󥦪�parent */
    while ((i != 1) && (val > heap[i/2]))	
    {
        heap[i] = heap[i / 2];	/* parent���ȤU����Ŧ� */
        i /= 2;			/* parent�W�� */
    }

    /* �𬰪ũέn�[�J���Ƥj�󥦪�parent�A������Jheap */
    heap[i] = val; 		
}
void deleteMax(){
    int parent, child, temp;
	
    if (num == 0){		
 		cout << "Heap�O�Ū� " << endl;
		return;
    }

    temp = heap[num--];		/* �Otemp��heap���̫�@�Ӽ� */

    parent = 1;
    child = 2;
    cout << "�R�� " <<heap[parent] << endl;

    while (child <= num)		
    {
        /* ���O�̫�@�Ӽ� �B ���l��>�k�l�� */
        if ((child < num) && (heap[child]) < heap[child + 1])
            child++;		/* ��ܥk�l��*/

        /* �p�G�̫�@�ӼƸ��p ���Xwhile�j�� */
        if (temp >= heap[child]) 
            break;
		   heap[parent] = heap[child];     /* child���ȩ��parent������l */
        parent = child;		       /* �쥻��child��parent */
        child *= 2;		       /* �s��child�U�� */
    }
    /* �̫�@�ӼƬ��𪺳̤j�ȡA��������� */
    heap[parent] = temp;	
}

int main(){
    int input,val;
    int num = 0;	
		
    do{
    	system("cls");	      /* �M�ŵe�� */

        cout << endl; 
        cout << "�o�O�@�ӳ̤p��n���{��:" << endl; 
        cout << "(1)�s�W�@�ӭ�<insert>" << endl; 
        cout << "(2)�R���̤j��<deleteMax>" << endl; 
        cout << "(3)�C�L��Ӱ�n<printHeap>" << endl; 
        cout << "(4)���}�{��<Exit>" << endl; 
        cout << "��J�n���檺�ﶵ:" ; 
    cin >> input;
    cout << endl;

    switch (input)	{
        case 1:	
	    	cout << "��J0�H�פ�" << endl; 				
	    do{
			cout << " ��J�s�W����: ";
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
		cout << " �п�J1-4���Ʀr " << endl;
		system("PAUSE");
	}
    } while (input != 4);

    system("PAUSE");
    return 0;
}	

