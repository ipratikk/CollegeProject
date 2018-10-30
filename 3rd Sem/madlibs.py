'''

Madlibs- a fun game with unknown words to form a story!!

Soltuion by - Pratik Goel (@ipratikk)

'''


import random
def getKeys(formatString):
    '''formatString is a string with dictionary keys.
    Return a set containing all the keys from the string.'''
    keyList = list()
    end = 0
    repetitions = formatString.count('{')
    for i in range(repetitions):
        start = formatString.find('{', end) + 1 # pass the '{'
        end = formatString.find('}', start)
        key = formatString[start : end]
        keyList.append(key) # may add duplicates
    return set(keyList) # removes duplicates: no duplicates in a set

def addPick(cue, dictionary): # from madlibDict.py
    '''Prompt for a user response using the cue string,
    and place the cue-response pair in the dictionary.'''
    promptFormat = "Enter a specific example for {name}: "
    prompt = promptFormat.format(name=cue)
    response = input(prompt)
    dictionary[cue] = response                                                             

def getUserPicks(cues):
    '''Loop through the collection of cue keys and get user choices.
    Return the resulting dictionary.'''
    userPicks = dict()
    for cue in cues:
        addPick(cue, userPicks)
    return userPicks

def tellStory(storyFormat):
    '''storyFormat is a string with dictionary references,
    in the form {cue}. Prompt the user for the mad lib cues
    and then print the resulting story with the cues.'''
    cues = getKeys(storyFormat)
    userPicks = getUserPicks(cues)
    story = storyFormat.format(**userPicks)
    print(story)

def main():
    originalStoryFormat = ['''\n\nOnce upon a time, deep in an ancient jungle,\nthere lived a {animal}.  This {animal}\nliked to eat {food}, but the jungle had\nvery little {food} to offer.  One day, an\nexplorer found the {animal} and discovered\nit liked {food}.  The explorer took the\n{animal} back to {city}, where it could\neat as much {food} as it wanted.  However,\nthe {animal} became homesick, so the\nexplorer brought it back to the jungle,\nleaving a large supply of {food}.\n\nThe End\n''',
'''\n\nOne of the most {adjective} things about graduating is that my\n{plural noun} are {verb ending in 'ing'} a huge party! I decided\nto have a backyard barbecue for all of my family and {plural noun 2}.\nI've invited my best friends {celebrity(female)},{Person in room(male)},\nand of course my teacher Mrs.{silly word}. My dad is going\nto {verb} hamburgers and {type of food(plural)} on his\nshiny new {noun}. He always thinks his {type of food(plural)}\ntaste really {adjective 2}, but i think they taste like {adjective 3}\n{type of shoe(plural)}. My mom is going to make her famous\n{something alive} salad, which is my favourite {noun 2}\never ! Mom said after we finish {verb ending in 'ing' 2}, we can go\nswimming in our new {noun 3}. {Silly word 2}!''',
'''\n\nToday I went to the zoo. I saw a(n)\n{adjective} {Noun} jumping up and down in its tree.\nHe {verb, past tense} {adverb}\nthrough the large tunnel that led to its {adjective}\n{noun}. I got some peanuts and passed\nthem through the cage to a gigantic gray {noun 2}\ntowering above my head. Feeding that animal made\nme hungry. I went to get a {adjective 2} scoop\nof ice cream. It filled my stomach. Afterwards I had to\n{verb} {adverb} to catch our bus.\nWhen I got home I {verb 2, past tense} my\nmom for a {adjective 3} day at the zoo.\n''',
'''\nOne very nice morning near the end of summer,\nmy mother woke me up at 4:00 A.M. and said, "Wake\nup and smell the grass, sleepy head! Today is your\nfirst day of school and you can't be late." I groaned in\nmy bed for twenty seconds, but eventually I got\ndressed. I wore a blue and white striped, long sleeve\n{noun} with a collar on it, a red tie,\ndark gray pants, white socks, black shoes, and a(n)\n{adjective} hat. In ten minutes I made\nlunch and ate my breakfast. {number}\nminutes later, the bus came. A few minutes later, I\nwas at school.\nIn school, I met two really\n{adjective} kids. All of us became\nfriends very fast. That day we had Science, and\nluckily my friends and I were at the same\n{noun 2} .My friends' names are\n{proper noun} and\n{proper noun 2}. In Math we weren't\ntogether, and that really bugged me. We learned what\n{plural noun} were, and when to use\nthem. At snack and recess, we played a game\ntogether. It was extremely fun. At P. E., we were\n{-ing verb} off of the ropes onto\n{plural noun 2}. I thought it was a very\n{adjective 2} idea. In swimming class,\nwe needed to swim extremely\n{adverb}, or else we would have to\nswim longer.\nBefore I knew it, school was over. I grabbed all\nmy belongings and put them into my backpack. In two\nminutes, the bus came. As I stepped into the bus I\nshouted, "Goodbye, adios amigos, and shalom," to\nmy friends. Then I went into the bus. In a flash, I was\nback home. This day was an extremely exciting day!''',
'''There is a new toy on the market that has everyone saying\n{exclamation}! It is called the {sound}\n{adjective} {noun} box, and will be in stores in\n{a month}. The {sound}\n{adjective} {noun} box is a new gadget that\nlets you do just about anything!\nIt {verb}s, it {verb 2}s, and it even serves\n{a beverage}! It is easy to operate and requires no\ninstructions!\nYou can also have it custom made any size up to\n{number} inches or a {color} to glow in the\ndark at no extra charge! The original product is pocket-sized and\n{color 2}. There are {number 2} jacks on the\nproduct for 6V DC power and for upgrades and add-ons. You can add\nhead-phones, {plural noun} monitors, {plural noun 2},\nand more! It’s possible to use them all at the same time!''']
    print("Enter 1 to Start and 0 to exit")
    x=int(input())
    while(x!='0'):
        tellStory(random.choice(originalStoryFormat))
        print("\n\nEnter 1 to go again or 0 to exit")
        x=input()
    print("Thank You")

main()
