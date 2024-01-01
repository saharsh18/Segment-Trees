//
//
//  CS 201 c coding
//
//
//

// #include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Driver Code
int tree0[7202];
int tree1[7202];
int tree2[7202];

void build(int arr[], int n, int tree[]) // build function using bottom up approach
{
    for (int i = 0; i < n; i++)
    {
        tree[n + i] = arr[i];
    }

    for (int i = n - 1; i > 0; --i)
    {
        tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }
}

int query(int l, int r, int tree[], int n)
{
    int res = 0;

    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1) // meaning l is odd or not
        {
            res += tree[l++];
        }

        if (r & 1)
        {
            res += tree[--r];
        }
    }

    return res;
}

void updateTreeNode(int p, int value, int tree[], int n) // similar to build is update which is just for a single node
{
    tree[p + n] = value;
    p = p + n;

    for (int i = p; i > 1; i >>= 1)
    {
        tree[i >> 1] = tree[i] + tree[i ^ 1];
    }
}

int main()
{
    // Substitute the full file path
    // for the string file_path

    int server0[3601] = {0};
    int server1[3601] = {0};
    int server2[3601] = {0};
    char ch[100];
    printf("Enter the file name with .csv\n");
    scanf("%s", ch);
    FILE *fp = fopen(ch, "r");

    if (!fp)
        printf("Can't open file\n");

    else
    {
        // Here we have taken size of
        // array 1024 you can modify it
        char buffer[1024];

        int row = 0;
        int column = 0;

        while (fgets(buffer,
                     1024, fp))
        {
            column = 0;
            row++;

            // To avoid printing of column
            // names in file can be changed
            // according to need
            if (row == 1)
                continue;

            // Splitting the data
            char *value = strtok(buffer, ", ");

            while (value)
            {
                // Column 1
                if (column == 0)
                {
                    int x = (((int)value[0] - (int)'0') * 600) + (((int)value[1] - (int)'0') * 60) + (((int)value[3] - (int)'0') * 10) + (((int)value[4] - (int)'0'));

                    server0[x]++;
                }

                // Column 2
                if (column == 1)
                {
                    int x = (((int)value[0] - (int)'0') * 600) + (((int)value[1] - (int)'0') * 60) + (((int)value[3] - (int)'0') * 10) + (((int)value[4] - (int)'0'));

                    server1[x]++;
                }

                // Column 3
                if (column == 2)
                {
                    int x = (((int)value[0] - (int)'0') * 600) + (((int)value[1] - (int)'0') * 60) + (((int)value[3] - (int)'0') * 10) + (((int)value[4] - (int)'0'));

                    server2[x]++;
                }
                value = strtok(NULL, ", ");
                column++;
            }
            // calling individual build functions
            build(server0, 3601, tree0);
            build(server1, 3601, tree1);
            build(server2, 3601, tree2);
        }

        while (1)
        {
            int q;
            printf("1.Server Data Update\n");
            printf("2.Query\n");
            printf("3.Quit\n");
            printf("Enter your choice of query : ");
            scanf("%d", &q);

            if (q == 1)
            {
                char c[1000];
                printf("Enter server data csv file name :\n");
                scanf("%s", c);
                FILE *f;
                f = fopen(c, "r");
                if (!f)
                    printf("Can't open file\n");

                else
                {
                    // Here we have taken size of
                    // array 1024 you can modify it
                    char buffer[1024];

                    int row = 0;
                    int column = 0;

                    while (fgets(buffer,
                                 1024, f))
                    {
                        column = 0;
                        row++;
                        if (row == 1)
                            continue;

                        // Splitting the data
                        char *value = strtok(buffer, ", ");

                        while (value)
                        {
                            // Column 1
                            if (column == 0)
                            {
                                int x = (((int)value[0] - (int)'0') * 600) + (((int)value[1] - (int)'0') * 60) + (((int)value[3] - (int)'0') * 10) + (((int)value[4] - (int)'0'));

                                server0[x]++;
                                updateTreeNode(x, server0[x], tree0, 3601);
                            }
                            if (column == 1)
                            {
                                int x = (((int)value[0] - (int)'0') * 600) + (((int)value[1] - (int)'0') * 60) + (((int)value[3] - (int)'0') * 10) + (((int)value[4] - (int)'0'));

                                server1[x]++;
                                updateTreeNode(x, server1[x], tree1, 3601);
                            }
                            if (column == 2)
                            {
                                int x = (((int)value[0] - (int)'0') * 600) + (((int)value[1] - (int)'0') * 60) + (((int)value[3] - (int)'0') * 10) + (((int)value[4] - (int)'0'));

                                server2[x]++;
                                updateTreeNode(x, server2[x], tree2, 3601);
                            }
                            value = strtok(NULL, ", ");
                            column++;
                        }
                    }
                    printf("Server Data updated Succuessfully !\n");
                }
            }
            else if (q == 2)
            {

                printf("Queries Available :\n");
                printf("1.Total clicks from a particular server in a time period.\n");
                printf("2.Total clicks from all the servers combined in a time period.\n");

                int choice;
                printf("Enter your choice : ");
                scanf("%d", &choice);

                if (choice == 1)
                {
                    printf("Enter Server number : ");
                    int x;
                    scanf("%d", &x);
                    int t1, t2;
                    printf("Enter Starting second : ");
                    scanf("%d", &t1);
                    printf("Enter Ending second : ");
                    printf("the no. of clicks are\n");
                    scanf("%d", &t2);
                    if (x == 0)
                    {
                        printf("%d\n", query(t1, t2, tree0, 3601));
                    }
                    else if (x == 1)
                    {
                        printf("%d\n", query(t1, t2, tree1, 3601));
                    }
                    else if (x == 2)
                    {
                        printf("%d\n", query(t1, t2, tree2, 3601));
                    }
                }
                else if (choice == 2)
                {
                    int t1, t2;
                    printf("Enter Starting second : ");
                    scanf("%d", &t1);
                    printf("Enter Ending second : ");
                    scanf("%d", &t2);
                    printf("the total no. of clicks for all servers is : ");
                    int su = query(t1, t2, tree0, 3601) + query(t1, t2, tree1, 3601) + query(t1, t2, tree2, 3601);
                    printf("%d\n", su);
                }
            }

            else
            {
                break;
            }
        }
        fclose(fp);
    }
    return 0;
}