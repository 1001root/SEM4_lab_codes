from bs4 import BeautifulSoup
import urllib.request
choose_Item = (input("input your website:  "))
resp = urllib.request.urlopen("https://"+choose_Item)
soup = BeautifulSoup(resp,"lxml", from_encoding=resp.info().get_param('charset'))
f=open(choose_Item + ".txt", 'w+')
for link in soup.find_all('a', href=True):
        print(link['href'])
        f.write(link['href'] + "\n")
f.close()
