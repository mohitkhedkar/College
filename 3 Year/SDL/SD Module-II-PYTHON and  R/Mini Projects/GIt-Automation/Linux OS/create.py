#!/usr/bin/env python3

import argparse
import os
import requests
from dotenv import load_dotenv

load_dotenv()

GITHUB_TOKEN =os.getenv("GITHUB_TOKEN")


parser = argparse.ArgumentParser()
parser.add_argument("--name", "-n", type=str, dest="name", required=True)
parser.add_argument("--private", "-p", dest="is_private", action="store_true")
args = parser.parse_args()
repo_name = args.name
is_private = args.is_private

REPO_PATH = " "           # add your direectory path where you want the projects. 
GITHUB_USER = ' '            # add your github username.
GITHUB_URL = "https://api.github.com"

if is_private:
    payload = '{"name": "' + repo_name + '", "private": true }'
else:
    payload = '{"name": "' + repo_name + '", "private": false }'

headers = {
    "Authorization": "token " + GITHUB_TOKEN,
    "Accept": "application/vnd.github.v3+json"
}

try:
    r = requests.post(GITHUB_URL + "/user/repos", data=payload, headers=headers)
    r.raise_for_status()
except requests.exceptions.RequestException as err:
    raise SystemExit(err)

try:
    os.chdir(REPO_PATH)
    os.system("mkdir " + repo_name)
    os.chdir(repo_name)
    os.system('git init')
    os.system('git remote add origin https://github.com/' + GITHUB_USER + '/' + repo_name + '.git')
    os.system(f'echo "# {repo_name}" >> README.md')
    os.system('git add README.md')
    os.system('git commit -m "Initial Commit" ')
    os.system('git branch -M main')
    os.system('git push origin main')
    os.system('code .')

except FileExistsError as err:
    raise SystemExit(err) 
    
