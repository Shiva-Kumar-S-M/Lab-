#include<stdio.h>
#define max 25
void main()
{
	int frag[max],block_size[max],file_size[max],i,j,no_blocks,no_files,diff;
	static int bf[max],block_no[max];
	printf("Memory Management Scheme - First Fit");
	printf("\nEnter the number of blocks:");
	scanf("%d",&no_blocks);
	printf("Enter the number of files:");
	scanf("%d",&no_files);
	printf("\nEnter the size of the blocks:-\n");
	for(i=1;i<=no_blocks;i++)
	{
		printf("Blocks %d:",i);
		scanf("%d",&block_size[i]);
	}
	printf("Enter the size of the files :-\n");
	for(i=1;i<=no_files;i++)
	{
		printf("File %d:",i);
		scanf("%d",&file_size[i]);
	}
	for(i=1;i<=no_files;i++)
	{
		diff=0;
		for(j=1;j<=no_blocks;j++)
		{
			if(bf[j]!=1)
			{
				diff=block_size[j]-file_size[i];
				if(diff>= 0)
				{
					block_no[i]=j;
					break;
				}
			}
		}
		frag[i]=diff;
		bf[block_no[i]]=1;
	}
	printf("\nFile_no:\tFile_size:\tBlock_no:\tBlock_size:\tFragment");
	for(i=1;i<=no_files;i++)
	{
		printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,file_size[i],block_no[i],block_size[block_no[i]],frag[i]);
	}
}
	