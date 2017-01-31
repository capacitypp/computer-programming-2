for i in `seq 1 50`; do
	URL="http://www.kde.cs.tut.ac.jp/~aono/data/images/1"
	if [ $i -lt 10 ]; then
		URL=${URL}"0"
	fi
	URL=${URL}${i}".jpg"
	curl -O ${URL}
done

