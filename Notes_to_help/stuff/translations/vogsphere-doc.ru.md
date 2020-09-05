# Vogsphere - Пособие / Manual #

Презентационная форма для подачи заявок
> Presidential form for turn in requests

Краткое изложение: Это пособие объясняет как использовать Vogsphere, a.k.a система сдачи работ Школы 42, включая основы git. Git - это утилита, которая использует Vogsphere, по контролю версий.
> Summary: This manual explains how to use the Vogsphere, a.k.a 42’ turn-in system, including git basics. Git is the version-control software the Vogsphere uses.

------------

## Chapter I ##
### Вступление / Forewords ###

| !             |
| ------------- |
| НИКОГДА НЕ ТЯНИТЕ с командой ```git clone``` вашего репозитория, чтобы начать работу с ним. Таким образом, если что-то пойдет не так, у вас будет достаточно времени, чтобы разобраться с этим.
> NEVER WAIT FOR THE LAST MINUTE to clone your repository and to start using it. Thus, if anything goes wrong, you’ll have plenty of time to resolve it.

| !             |
| ------------- |
| Пожалуйста учтите, что студенты, которые просят о помощи в отношении Vogshpere за несколько часов до закрытия репозитория, увидят ответ на их же вопрос "вы должны были прийти намного раньше !", и по сути они заслуживают такой ответ.
> Please note that students who ask for help regarding to the Vogsphere a few hours before the repositories close will see themselve answer something like “you should have come way earlier !”, and thy will deserve such an answer.

### I.1 Git ###

* Git - менеджер по распределению контроля версий. Этот инструмент мы используем для хранения и управления версиями практически для каждого проекта в Школе 42.
  > Git is a distributed version control manager. It’s the tool we use to store and version your turn-ins for virtually every project at 42.

* В ваших же интересах получить знания о Git и его использовании. В этом руководстве описывается только очень ограниченный аспект этого невероятного программного обеспечения. Вы быстро получите все необходимые знания, читая документацию о git в интернете. Это спасет вас от множества проблем.
  > It’s your responsability to acquire knowledge of Git and its use. This manual only covers a very limited aspect of this incredible software. One can acquire this knowledge very fast by reading git’s documentation online. This will save you lots of troubles.

### I.2 Несколько направлений / A few directions ###

Вот несколько ссылок, где вы сможете найти ценную читабельную документацию о Git:
> Here are a couple of links where you can find good quality documentations regarding Git:

* Официальная документация: git-scm.com
* [Классное пособие](https://ru.lmgtfy.com/?q=learning+git)

------------

## Chapter II ##
## Работы с Vogsphere / Vogsphere operations ##

| !             |
| ------------- |
| С этого момента данное руководство считает, что вы уже ознакомились с документацией по Git. Не будьте дураком и потратьте свое время на изучение, прежде чем выходить за рамки этого пункта.
> From this point, this manual considers that you have read Git’s documentation. Don’t be a fool and take your time to read it before going beyond this point.

### II.1 Вкратце / Summary ###

* Когда вы регистрируетесь в проекте, для вас автоматически создается уникальный и персональный репозиторий для вас и вашей команды, и для этого конкретного проекта.
  > When you register to a project, a unique and personnal repository for you of your team and for this specific project is automaticaly created.

* Вы можете найти ссылку на ваш репозиторий на странице в intranet.
  > You can find your repository’s url on the intranet on your project’s page.

* Ссылка на репозиторий выглядит как-то так:
  > A repository’s url looks more or less like this:
  
```vogsphere@vogsphere.42.fr:pisc-0-2013/paris-0-1/j00/yourlogin```

* Далее, вы должны получить свежую локальную копию вашего репозитория с помощью команды ```git clone```.
  > Next, you have to fetch a fresh local copy of your repository using the git clone command.

* Далее, работайте с локальной копией. Как только вы закончите, или когда захотите уведомить Git о вашей проделанной работе, то выполните это:
  > Next, you’re going to work on this local copy. Once done, or whenever you’d like to notify Git of your work, you must:
  * Добавить изменения, используя команду ```git add```
    > Add the modifications by using the git add command
  * Записать индексированные изменения, используя команду ```git commit```
    > Create a new revision by using the git commit command.

* Вы можете проверить статус вашего локального репозитория в любое время, используя команду ```git status```.
  > You can check the status of your local repository at anytime by using the git status command.

* Пошагово записывая индексированные изменения, вы можете исправлять столько раз, сколько захотите. Прочтите документацию, чтобы понять, почему это хорошая идея...
  > By commiting your work step by step, you can create as much revisions as you want. Read the documentation to understand why it’s a good idea to do so...

* Чтобы отправить ваши изменения в Vogspher'у (т.е. в репозиторий, который будет оцениваться), вам нужно использовать команду ```git push```. не забудьте указать место назначения ```git push origin master```, когда в самый первый раз будете использовать ```git push```.
  > To send your revisions to Vogsphere’s side (i.e. to the repository that’s going to be used for evaluations), you have to use the git push command. On your very first push to a repository, don’t forget to specify the destination (git push origin master).

* После успешного выполнения push, все ваши изменения будут находиться на копии в Vogsphere вашего репозитория и будут видны в процессе оценки.
  > After a successful push, all your revisions will exist on Vogsphere’s copy of your repository and will be visible during evaluation.

* Очевидно, что любые созданные изменения на вашей локальной копии после push не будут существовать в копии репозитория на Vogsphere. Вы также должны выполнить push файлов, к счастью это не происходит автоматически. Будет очень грустно работать со сложным проектом и забыть push фалов, не правда ли?
  > Obviously, any revisions created on your local copy after a push won’t exist on Vogsphere’s copy of your repository. You must push them as well, this is (fortunately) not automatic. It would be a shame to work hard on a project and forget to push it, wouldn’t it?

* Вы можете сделать свежий clone вашего репозитория в текущую папку, в любое время, если вы хотите проверить, что было успешно выгружено (т.е. какие данные имеются на копии репозитория в Vogsphere).
  > If you wish to check what have been effectively turned in (i.e. which data is available on Vogsphere’s copy of your repository) at anytime, you can clone a fresh local copy of your repository in a temporary folder. This clone will be the exact copy of what you would have turned in if the evaluation would happen right now.

* Когда работаете в команде (в каких-то проектах или rush'ах), вы столкнетесь с вопросами по синхронизации локальной копией репозитория вашей команды, между ее участниками. Существуют несколько решений этой проблемы, которые подробно описаны в документации по Git...
  > When you work as a team (for some projects or rushes), you will face synchronisation issues between each team member’s local copy of your team’s repository. Several solution to solve this exist and are covered in detail in Git’s documentation...

### II.2 Пример / Exemple ###

* Вот краткий пример работы с репозиторием используя Vogsphere (очевидно, что ссылки будут отличаться):
  > Here is a quick sample of operating a repository using Vogsphere (obviously, the urls will differ):
```
zaz@blackjack ~ $ cd work
zaz@blackjack work $ git clone vogsphere@vogsphere.42.fr:pisc-0-001/2013/paris-0-1/d00/demo d00
Cloning into 'd00'...
vogsphere: (INFO) This transaction has been started at 2013-06-17 16:19:35, server time.
vogsphere: (INFO) Rights will be determined using this time, so do NOT cut the connection.
vogsphere: (INFO) You have read and write rights on this repository
warning: You appear to have cloned an empty repository.
zaz@blackjack work $ cd d00
zaz@blackjack d00 $ vim test.c
zaz@blackjack d00 $ git add test.c
zaz@blackjack d00 $ git commit -m "Added test.c"
[master (root-commit) be2069b] Added test.c
1 file changed, 4 insertions(+)
create mode 100644 test.c
zaz@blackjack d00 $ vim test2.c
zaz@blackjack d00 $ git add test2.c
zaz@blackjack d00 $ git commit -m "Added test2.c"
[master f195334] Added test2.c
1 file changed, 6 insertions(+)
create mode 100644 test2.c
zaz@blackjack d00 $ git push origin master
vogsphere: (INFO) This transaction has been started at 2013-06-17 16:22:52, server time.
vogsphere: (INFO) Rights will be determined using this time, so do NOT cut the connection.
vogsphere: (INFO) You have read and write rights on this repository
Counting objects: 9, done.
Delta compression using up to 4 threads.
Compressing objects: 100% (8/8), done.
Writing objects: 100% (9/9), 897 bytes, done.
Total 9 (delta 1), reused 0 (delta 0)
To vogsphere@vogsphere.42.fr:pisc-0-001/2013/paris-0-1/d00/demo
* [new branch] master -> master
zaz@blackjack d00 $ echo "/* New modification */" >> test2.c
zaz@blackjack d00 $ git commit -am "Commiting a modification without git add, you fool"
[master ba0a82a] Commiting a modification without git add, you fool
1 file changed, 1 insertion(+)
zaz@blackjack d00 $ git push
vogsphere: (INFO) This transaction has been started at 2013-06-17 16:23:35, server time.
vogsphere: (INFO) Rights will be determined using this time, so do NOT cut the connection.
vogsphere: (INFO) You have read and write rights on this repository
Counting objects: 5, done.
Delta compression using up to 4 threads.
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 351 bytes, done.
Total 3 (delta 1), reused 0 (delta 0)
To vogsphere@vogsphere.42.fr:pisc-0-001/2013/paris-0-1/d00/demo
a6f17c3..ba0a82a master -> master
zaz@blackjack d00 $
```

### II.3 Пожалуйста запомните это / Please remember the followings ###

| !             |
| ------------- |
| Установлена строгая квота в 100MB в репозитории на Vogsphere. Будьте осторожны с этим, потому что превышение квоты будет рассматриваться как злоупотребление ресурсами и вследствии этого последуют наказания!
> Vogsphere enforces a strict quota of 100MB per repository. Be very careful about that, because exceeding the quota will be considered as an abuse of resources, and will be punished as such!

* Vogsphere использует тикеты Kerberos, для авторизации. Тикет автоматически приобретается, когда вы входите в систему. Однако, через некоторые время тикет истекает. Вы можете приобрести новый тикет с помощью команды ```kinit```, если у вас не получается воспользоваться Vogsphere.
  > Vogsphere uses a Kerberos ticket to authentify you. A ticket is automaticaly acquired when you log in your session. However, after some time, this ticket will expire. If you are unable to use Vogsphere, you can acquire a new ticket by using the kinit command.

* Даты и точное время закрытия репозиториев для сдачи будут указаны на странице в intranet. У вас все еще будет возможность просмотреть ваш репозиторий, но не будет возможности выполнить push каких-либо данных.
  > Your turn-in repositories will close at the exact date and time specified on your project’s page on the intranet. You will still have a read-access on your repository, but you won’t be allowed to push data anymore.

* Когда вы подключаетесь к Vogsphere, дата и время, используемые для проверки вашего доступа на запись в репозитории на Vogsphere, являются датой и временем вашего подключения к Vogsphere. Если слишком много студентов попытаются выполнить push данных одновременно, то ваш запрост будет выставлен в очередь (Vogsphere вас уведомит об этом). Не волнуйтесь, до тех пор, пока вы не прервете соединение или не выполните push перед сроком сдачи, то ваш push будет принят если дата и время подачи уже истекли. Но в любом случае, кто будет настолько глуп, чтобы сдавать свою работу в последний момент...
  > When you connect to Vogsphere, the date and time used to check your write access to your repository on Vogsphere is the date and time of your connection to Vogsphere. If too many students try to push data at the very same time, your request will be queued (Vogsphere will notify you). Don’t worry, as long as you don’t cut the connection or you make your push before the deadline, you push will be accepted if the turn in date and time expired. But anyway, who could be silly enough to turn his/her work in at the last moment...