import requests
import json

competition_name = "UEFA Champions League"
year = "2011"

def getWinnerTotalGoals(competition_name, year):
    competition_winner_url = 'https://jsonmock.hackerrank.com/api/football_competitions?name=' + str(competition_name) + '&year=' + str(year)
    competition_request = requests.get(competition_winner_url)
    competition_result = json.loads(competition_request.content)
    winner_team = competition_result['data'][0]['winner']
    url1 = 'https://jsonmock.hackerrank.com/api/football_matches?competition='+str(competition_name)+'&year='+str(year)+'&team1='+str(winner_team)+'&page=1'
    team1_request = requests.get(url1)
    team1_result = json.loads(team1_request.content)
    total_pages = team1_result['total_pages']
    per_page = team1_result['per_page']
    sum = 0
    for i in range(1, total_pages + 1):
        url = 'https://jsonmock.hackerrank.com/api/football_matches?competition=' + str(competition_name) + '&year=' + str(year) + '&team1=' + str(winner_team) + '&page=' + str(i)
        team1_request = requests.get(url).json()
        try:
            for j in range(0, per_page):
                team1 = team1_request['data'][j]['team1goals']
                sum += int(team1)
        except:
            pass
    url2 = 'https://jsonmock.hackerrank.com/api/football_matches?competition='+str(competition_name)+'&year='+str(year)+'&team2='+str(winner_team)+'&page=1'
    team2_request = requests.get(url1)
    team2_result = json.loads(team2_request.content)
    total_pages = team2_result['total_pages']
    per_page = team2_result['per_page']
    for i in range(1, total_pages + 1):
        url = 'https://jsonmock.hackerrank.com/api/football_matches?competition=' + str(competition_name) + '&year=' + str(year) + '&team2=' + str(winner_team) + '&page=' + str(i)
        team2_request = requests.get(url).json
        try:
            for j in range(0, per_page):
                team2 = team2_request['data'][j]['team2goals']
                sum += int(team2)
        except:
            pass
    print(sum)
getWinnerTotalGoals(competition_name, year)
