#autocsdn.sh
#automatically send request to csdn blog

user=dextrad_ihacker
articles='curl -s "http://blog.csdn.net/$user/" | grep 'href' | egrep -o "$user/articles/details/[[:digit:]]+" | sort | uniq'

for i in `seq 1000`

do

for article in $articles
  do
  curl -s "http://blog.csdn.net/$article" > /dev/null
  sleep 2
  echo "One Shot"
  done

echo $i

done
