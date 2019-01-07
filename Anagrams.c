#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(char *x,char *y)
{
	char temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

void permutations(char *a,int low,int high)
{
	int i;
	FILE *fp;
	fp=fopen("Anagrams.txt","a+");
	if(low==high)
	{
		fprintf(fp,"%s",a);
		fclose(fp);
	}
	else
	{
		for(i=low;i<=high;i++)
		{
			swap((a+low),(a+i));
			permutations(a,low+1,high);
			swap((a+low),(a+i));
		}
	}
}

void search(char *a)
{
	FILE *fp;
	char *line;
	size_t len=0;
	ssize_t read;
	fp=fopen("dictionary.txt","r");
	if(fp==NULL)
		exit(1);
	while((read=getline(&line,&len,fp))!=-1)
	{
		if(!strcmp(a,line))
			printf("%s",a);
	}
	fclose(fp);
}

int main()
{
	char str[10];
	int n,i,j,k,m;
	FILE *fp2;
	fp2=fopen("Permutations.txt","a+");
	scanf("%s",str);
	n=strlen(str);
	for(i=1;i<=n;i++)
        {
                for(j=0;j<=n-i;j++)
                {
                        m=j+i-1;
                        for(k=j;k<=m;k++)
                                fprintf(fp2,"%c",str[k]);
                        fprintf(fp2,"\n");
                }
        }
        fclose(fp2);

	FILE *fp;
	//printf("Enter the letters\n");
	//scanf("%s",str);
	fp=fopen("Permutations.txt","r");
	
	//permutations(str,0,n-1);
        //t=clock()-t;
        //double time_taken = ((double)t)/CLOCKS_PER_SEC;
        //FILE *fp;
        char *line;
        size_t len=0;
        ssize_t read;
        //fp=fopen("Anagrams.txt","r");
        while((read=getline(&line,&len,fp))!=-1){
		n=strlen(line);
                permutations(line,0,n-2);
	}
	fclose(fp);
	FILE *fp1;
	char *line1;
	size_t len1=0;
	ssize_t read1;
	fp1=fopen("Anagrams.txt","r");
	while((read1=getline(&line1,&len1,fp1))!=-1)
		search(line1);
	fclose(fp1);
	return 0;
}
