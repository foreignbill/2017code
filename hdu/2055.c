main(n,c){int a;scanf("%d%*c",&n);while(n--&&scanf("%c%d%*c",&c,&a))printf("%d\n",a+(c<97?c-64:96-c));}
