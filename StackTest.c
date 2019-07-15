#include<stdio.h>
#include<stdlib.h>
#define ArraySize 10
#define ArrayExpanse 10
typedef int type;
typedef struct Array{
	type *top;
	type *base;
	int Size;
}Array;

void *init(Array *s){
	s->base = (type*)malloc(sizeof(type)*ArraySize);
	if (!s->base){
		exit(0);
	}
	s->top = s->base;
	s->Size = ArraySize;
}

void *pusharray(Array *s,type n){
	if(s->top - s->base > ArraySize){
		printf("%d****\n",s->top - s->base);
		s->base = (type*)realloc(s->base,sizeof(type)*(ArrayExpanse+ArraySize));
		//printf("233++\n");
		s->top = s->base + ArraySize;
		s->Size = ArraySize + ArrayExpanse;
		if (!s->base){
		exit(0);
		}
	}
	*(s->top) = n;
	s->top++;
}

int printvalue(Array* s){
	while(1){
		if (s->base == s->top){ 
			return 1;
		}
		(s->top)--;
		printf("%d\n",*(s->top));
	}
}

type output(Array*s){
	type n;
	//free(s->top);
	if(s->top - s->base == 0)
	{
		return 1;
	}
	n = *(--s->top);
	return n;
} 
int destory(Array*s){
	while(1){
		free(s->base);
		if(s->base == s->top){
			return 1;
		}
		s->base++;
	}
} 
int main()
{
	Array *ernum = (Array*)malloc(sizeof(Array));
	printf("233\n");
	init(ernum);
	int i; 
	init(ernum);
	printf("%d......\n",ernum->Size);
	pusharray(ernum,5);
	pusharray(ernum,4);
	pusharray(ernum,output(ernum) - output(ernum));
	pusharray(ernum,3);
	pusharray(ernum,6);
	pusharray(ernum,output(ernum) + output(ernum));
	pusharray(ernum,output(ernum) * output(ernum));
	printvalue(ernum);
	destory(ernum);
	return 0;
}
