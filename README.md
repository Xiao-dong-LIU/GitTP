# A small project to practice git 
In this exercise, you’ll work with a Python script (`TP.py`), uncomment sections step-by-step by removing `#` before each line, commit changes, and run the script to see the output. The project runs in GitHub Codespaces and focuses on Git essentials with immediate feedback. The script starts empty and grows as you uncomment sections—perfect for learning Git workflows collaboratively.

Work in pairs (***Dev.A*** and ***Dev.B***) to achieve efficiency.
## 0. Initial Setup
Before diving into Git operations, configure your Git environment in Codespaces.
### SSH Key configuration
- In the Codespaces terminal:
  ```bash
  ssh-keygen -t ed25519 -C "your.email@example.com"
  ```
- Press Enter for default file (~/.ssh/id_ed25519), skip passphrase (press Enter twice).
- Add your SSH key to the ssh-agent
    ```bash 
    eval "$(ssh-agent -s)"
    ```
- Add SSH private key to the ssh-agent
    ```bash 
    ssh-add ~/.ssh/id_ed25519
    ```
- Copy the public key
     ```bash 
     cat ~/.ssh/id_ed25519.pub
    ```
- Add SSH Key to GitHub
    - Go to Settings > SSH and GPG keys > New SSH key.
    - Paste the key from the previous step.
    - Set title: “Class Key”.
    - Click Add SSH key.
- Test the connection:
     ```bash 
    ssh -T git@github.com
    ```
### Local configurations
- Set your name and email
```bash
git config --global user.name "John Doe"
git config --global user.email johndoe@example.com
```
- Set VS Code as the default editor:
```bash
git config --global core.editor "code --wait"
```
> The `--wait` flag ensures Git waits for VS Code to close before proceeding.
- Configure difftool to use VS Code
```bash
git config --global diff.tool vscode
git config --global difftool.vscode.cmd "code --wait --diff \$LOCAL \$REMOTE"
```
- Configure mergetool to use VS Code
```bash
git config --global merge.tool vscode
git config --global mergetool.vscode.cmd "code --wait --merge \$REMOTE \$LOCAL \$BASE \$MERGED"
```
- Add useful Git aliases
```bash
git config --global alias.st status
git config --global alias.ci commit
git config --global alias.br branch
git config --global alias.loggraph "log --all --decorate --oneline --graph"
git config --global alias.log1 "log --oneline"
```
> These shorten `git status` to `git st`, `git commit` to `git ci`,`git branch` to `git br` and add visual logs with `git loggraph` and `git log1`
- Verify your settings
```bash
git config --global --list
```
## 1. Fork the project
You don’t have write access to this repo, so fork it. Only one fork per pair!

- ***Dev.B***: Fork the project by clicking on the fork button in the upper right corner of the project page.

- Now ***Dev.B*** has his own copy of the project. In order to give ***Dev.A*** write permissions to the project,
- ***Dev.B*** needs to add ***Dev.A*** to the project’s list of collaborators: *Settings -> Collaborators*.

## 2. Clone the repository
In this part, ***Dev.B*** does the same thing as ***Dev.A***
- clone the remote to local and then go to the local repository 
```bash
git clone YourRemoteRepository
cd GitTP
```
- Visualize the workflow:
```bash
git loggraph
```
or by "Graph"
- Test the initial (empty) script:
```bash
python TP.py
```
> No output yet, since everything is commented out.
## 3. Commit and push
- ***Both*** check the status of this git repository
```
git statut
```
- ***Both*** Uncomment Step 1 (the "Welcome..." line), save and run it.
```bash
git statut
python TP.py
```
- ***Both*** stage the modifications (check graph)
```bash
git add TP.py
```
- ***Both*** commit this modifications 
```bash
git commit -m "uncomment Step 1 for A and uncomment Step 2 for B"
```
check graph

- ***Both*** push this commit
```bash
git push
```
> One of the teammates will find that it is not possible to push the modifications. Try to figure it out. 

> Tips: The teammate pushed after the first need to do `git pull` before the `git push`

- Try to get the same output for graph when finished. 

## 4. Branch and merge
- ***Dev.A***:
  - Create and checkout branch:
    ```bash
    git checkout -b Step2
    ```
  - Verify 
    ```bash
    git branch
    ```
  - Uncomment Step 2 (remove # from "def subtract..." and "print..."), save and run it.
  - Commit it 
    ```bash
    git add TP.py
    git ci -m "uncomment Step 2"
    ```
  - Create a new file ***dev_A_tools.py***:
  - Copy and paste this content into ***dev_A_tools.py***
   ```python
        # dev_A_tools.py
        def greet(name):
        return f"Hello, {name}!"
   ```
   - Update ***TP.py*** to use the function.
   - After Step 2, add:
   ```python
        from dev_A_tools import greet
        print(greet("Dev.A"))
   ```
  - Save and run.
  - Stage and commit
    ```bash
    git add TP.py dev_A_tools.py
    git ci -m "add greet function in dev_A_tools.py"
    ```
  - Merge to main and publish it
    ```bash
    git checkout main
    git pull
    git merge Step2
    git push
    ```
> Do not forget to check often with status and graph 
- ***Dev.B***:
  - Create and checkout branch:
    ```bash
    git checkout -b Step3
    ```
  - Verify 
    ```bash
    git branch
    ```
  - Uncomment Step 3, save and run it.
  - Commit it 
    ```bash
    git add TP.py
    git ci -m "uncomment Step 3"
    ```
  - Create a new file ***dev_B_tools.py***:
  - Copy and paste this content into ***dev_B_tools.py***
   ```python
        # dev_B_tools.py
        def square(number):
        return number * number
   ```
   - Update ***TP.py*** to use the function.
   - After Step 2, add:
   ```python
        from dev_B_tools import greet
        print("Square of 4:", square(4))
   ```
  - Save and run.
  - Stage and commit
    ```bash
    git add TP.py dev_B_tools.py
    git ci -m "add square function in dev_B_tools.py"
    ```
  - Merge to main and publish it
    ```bash
    git checkout main
    git pull
    git merge uncommentStep3
    git push
    ```
- ***Both*** try to get the same workflow on graph 

## 5. Manage conflicts 
- ***Dev.B***
    - create a new branch "uncommentStep4".
    - uncomment "Step 4", save and run it.
    - commit this modification and merge it to main branch. 
    - publish it to remote.
- ***Dev.A***
    - create a new branch "changeStep4".
    - uncomment "Step 4" and **change** the output from "Great job completing the steps!" to "Congratulations!"
    - Save and run it.
    - commit these modifications.
    - checkout to main.
    - do a `git pull` to update local main branch
    - merge branch "changeStep4" to main.  
    - publish it to remote.
    - Resolve conflict:
    ```bash
    git mergetool
    ```

> Here ***Dev.A*** has to handle the conflicts when merge "changeStep4" to main.  

## 6. Manage remote
- ***Dev.B***
    - create an annotated tag named "V1.0"
        ```bash
        git tag -a v1.0 -m "version 1.0"
        ```
    - publish this tag to remote
        ```bash
        git push origin v1.0 
        ```
    - Check tag in remote
- ***Dev.A*** 
    - fetche this tag to his local and check it on graph
- ***Both***
    - create a private empty project in Koda.
    - publish the project to Koda. 

## Fix a Bug and Cherry-Pick
In this part, you’ll check out an earlier commit, fix a bug in a new branch, and use `git cherry-pick` to apply the fix to `main`. This simulates fixing a mistake from the past and bringing the solution forward without merging an entire branch.
- ***Both***
    - Look for a commit like "uncomment Step 2"
    ```bash
    git log1
    ```
    - Checkout that commit into a new branch:
    ```bash
    git checkout -b fix-subtract-bug Hash (Hash: commit ID)
    ```
    - Check files that you have in your repository 
    ```bash
    ls 
    ```
    - change `return a + b` in the `Step 2` of `TP.py` to `return a - b`
    - save and run it
    - commit it if it is right
    ```bash
    git add TP.py
    git ci -m "fix subtract bug: change + to -"
    ```
    - Merge this ***commit*** to `main` branch
    ```bash
    git checkout main
    git pull
    git cherry-pick <fix-hash>
    ```
# Advanced Git Operations
In this section, you’ll explore advanced Git commands to modify your commit history: amending a commit, rebasing interactively to edit or squash commits, and changing old commit content. These skills help you refine your project history before sharing it.

## Amend a Commit
Imagine you forgot to add *Step 5* to your last commit—use `git commit --amend` to fix it.
  - Checkout `main` and ensure it’s up-to-date
  - Uncomment Step 5 in TP.py
  - Stage and commit
  - Realize you forgot a description—amend it
 	- Add a comment above Step 5
	```python
	# Step 5: Multiplication (multiply two numbers)
	```
	- Stage the change
	- Amend the last commit
## Interactive Rebase
### Edit an Old Commit
Let’s fix a typo in an earlier commit message from Section 3 (e.g., "uncomment Step 1" → "Uncomment Step 1").
- Start an interactive rebase from the commit before Section 3
- Find the commit before "uncomment Step 1", then
```bash
git rebase -i <hash-before>
```
- In the editor, change pick to edit for the "uncomment Step 1" commit, save, and exit.
- Git pauses at that commit. Edit the message
- Continue the rebase
```bash
git rebase --continue
```
- Visualize with graph
### Squash Commits
Combine your two commits from Section 4 (e.g., uncommenting and adding a function) into one.
- Start rebase from before Section 4
- Change `pick` to `squash` (or s) for the second commit (e.g., "add greet function..."), save, and exit.
- Edit the combined commit message
```text
Uncomment Step 2 and add greet function
```
- Save and exit
- Visualize with graph

### Edit Old Commit Content
Fix a typo in Step 3’s output from Section 4 (e.g., "Lucky number" → "Your lucky number").
- Rebase to edit the Step 3 commit
- Set `pick` to `edit` for "uncomment Step 3", save, and exit
- Modify TP.py
- Stage and amend
- Continue 
## Stash Uncommitted Changes
In this section, you’ll use `git stash` to save uncommitted changes, switch tasks, and apply them later. Imagine you’re working on *Step 7* but need to fix something in `main`—stash lets you pause without committing.
- Checkout `main`
- Uncomment Step 7 in `TP.py`
- Make a mistake—add a typo
```python
print("Sum of list:", sum(numbrs))  # Typo: numbrs instead of numbers
```
- Stage it
- Before committing, you’re interrupted—stash it
```bash
git stash push -m "working on Step 7 with typo"
```
- Verify it’s clean
- checkout to a new branch `ChangecommentinStep1`
```python
# Step 1: Basic output (welcome message)
print("Welcome to the Git exercise!")
```
instead of
```python
# Step 1: Basic output
print("Welcome to the Git exercise!")
```
- Commit it.
- Go back to `main` and list you stashes
- Apply your stashed changes
- Fix the typo
- Commit it
- List your stashes and remove useless ones 
- Merge `ChangecommentinStep1` to `main`
> Stash is great for quick pauses, but it’s a single stack—multiple stashes can get messy. Use `git stash list` to see saved stashes and `git stash apply <stash-id>` to apply specific ones without popping.
## Work with Git Worktrees
In this section, you’ll use `git worktree` to work on multiple branches at the same time in separate folders, without needing multiple clones. This is great for testing changes or developing features in parallel. You’ll create a worktree to test *Step 6* (user input) while keeping `main` intact.
### Create a Worktree
- Ensure you’re on `main`
- Create a worktree for the `Step6` branch (assume it doesn’t exist yet)
```bash
git worktree add ../step6-worktree -b Step6
```
> This creates a new branch `Step6` and a folder `../step6-worktree` with its contents.
- Navigate to the worktree
- Uncomment Step 6 in `TP.py` and run it
> Enter a name in the terminal to see the output (e.g., "Hello, Dev.A").
- Commit
### Compare with Main
- Go back to the main directory (GitTP)
- Check `TP.py—Step 6` is still commented out here.
- Run it
> No input prompt, since `main` doesn’t have Step 6 yet.
- List worktrees
- Compare with `git difftool`
### Merge the Worktree Branch
- Go to the main directory
- Merge `Step6` to `main` branch
- run the code
### Clean Up
- Remove the worktree and Verify
- Delete the branch `Step6`
> Worktrees let you experiment without disrupting your main workspace—ideal for testing features like `Step 6’s` input while keeping main stable. Use them when you need to juggle multiple tasks!

## Experiment with Git Reset
In this section, you’ll use `git reset` to rewind history in a branch, go back to the first commit, and then reset to a later commit—exploring how Git preserves commits even after a reset.

### Reset to the First Commit
- Create a new branch from `main`:
    ```bash
    git checkout -b reset-experiment
	```
- Find the first commit
	```bash
    git log --oneline --all
	```
- Reset to it
- Check history
> Only the first commit remains in `reset-experiment`
### Explore Reflog and Reset Forward
- In `reset-experiment`, view recent HEAD movements
	```bash
    git reflog
	```
- Find a later commit (e.g., "uncomment Step 3", hash<later-hash>).
- Reset to it with option `hard`
- Check history
> ####  Reset Insight #### 
> Reset moves your branch pointer, but commits aren’t lost—they’re in `reflog` for **30 days**. You can reset to any commit you know the hash for, even after rewinding to the first commit!
## Experiment with Git Revert
In this section, you’ll use `git revert` to undo a previous commit safely, keeping the history intact—unlike `reset`, which rewrites it. You’ll revert the bug fix in `Fix a Bug and Cherry-Pick`, then revert that revert to restore it.
- Find the cherry-pick commit
- Revert it
> Editor opens—keep the default message (e.g., "Revert 'fix subtract bug...'") or edit it, then save and exit.
- Run the code (bug returns)
### Revert the Revert
- Find the revert commit 
- Revert the revert
- Run the code (fix restored)
