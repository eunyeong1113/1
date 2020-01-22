#2.0, 2.1, 2.2, 2.3, 2.4, 2.5
import sys
import io
sys.stdout=io.TextIOWrapper(sys.stdout.detach(),encoding='utf-8')
sys.stderr=io.TextIOWrapper(sys.stderr.detach(),encoding='utf-8')

import requests
from bs4 import BeautifulSoup

LIMIT=50
URL=f"https://www.indeed.com/jobs?q=python&limit={LIMIT}"
def extract_indeed_pages():
    result = requests.get(URL)
    soup = BeautifulSoup(result.text,"html.parser")
    pagination=soup.find("div",{"class":"pagination"})

    links=pagination.find_all('a')
    pages=[]
    for link in links[:-1]:
        pages.append(int(link.string))
        #pages.append(link.find("span").string)
    #pages=pages[0:-1]   
    #print(pages[-1])

    max_page=pages[-1]
    return max_page
    #print(range(max_page))
    #for n in range(max_page):
     #   print(f'start={n*50}')


def extract_indeed_jobs(last_page):
    for page in range(last_page):
      result= requests.get(f"{URL}&start={page*LIMIT}")
      print(result.status_code)