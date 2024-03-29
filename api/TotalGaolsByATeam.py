import requests
import json

def getTotalGoals(team, year):
    url1 = "https://jsonmock.hackerrank.com/api/football_matches?year=" + str(year) + "&team1" + team
    url2 = "https://jsonmock.hackerrank.com/api/football_matches?year=" + str(year) + "&team2" + team
    response1 = requests.get(url1)
    result1 = json.loads(response1.content)
    response2 = requests.get(url2)
    result2 = json.loads(response2.content)
    curr_1 = 1
    total_page_url1 = result1['total_pages']
    curr_2 = 1
    total_page_url2 = result2['total_pages']
    total = 0
    while curr_1 <= total_page_url1:
        url1 = "https://jsonmock.hackerrank.com/api/football_matches?year={0}&team1={1}&page={2}".format(year,team,curr_1)
        response1 = requests.get(url1)
        result1 = json.loads(response1.content)
        for i in result1['data']:
            if i['team1'].upper() == team.upper():
                total += int(i['team1goals'])
        curr_1 += 1
    while curr_2 <= total_page_url2:
        url2 = "https://jsonmock.hackerrank.com/api/football_matches?year={0}&team2={1}&page={2}".format(year,team,curr_2)
        response2 = requests.get(url2)
        result2 = json.loads(response2.content)
        for i in result2['data']:
            if i['team2'].upper() == team.upper():
                total += int(i['team2goals'])
        curr_2 += 1
    return total


total_goal = getTotalGoals("Barcelona", 2011)
print (total_goal)

