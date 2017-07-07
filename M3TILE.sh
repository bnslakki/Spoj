dp[0]=1
dp[1]=3
for ((i=2;i<20;i++))
do
   dp[i]=$((4*${dp[i-1]}-${dp[i-2]}))
   #echo ${dp[i]}
done
for ((;;))
do
  read n
  if ((n==-1))
  then
  break
  fi
  if ((n%2==0))
  then
  	  t=$(($n/2))
      echo ${dp[$t]}
  else
  echo 0
  fi
done  
