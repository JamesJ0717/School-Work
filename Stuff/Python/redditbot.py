import praw
import re
import time

reddit = praw.Reddit(client_id='cvY7O5XIsYtPdw',
                     client_secret='nfD7cLg9GzdrOfwAtiwIhsFPw6Q',
                     user_agent='<console:reddit_bot:0.0.1 (by /u/HereForPuh)>',
                     username='HereForPuh',
                     password='Triplej7879')

i = 0
while (i <= 100):
    subreddit = reddit.random_subreddit(nsfw=True)
    print(subreddit)
    praw.models.Subreddit.subscribe(subreddit)
    i += 1
