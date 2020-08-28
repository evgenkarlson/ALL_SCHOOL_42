# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmei <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/01 00:47:22 by nmei              #+#    #+#              #
#    Updated: 2018/03/01 00:47:24 by nmei             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#
# ============================= ft_sommelier ===================================
#
# This Dockerfile setup assumes you are going to be using the same physical
# mac for a project. In theory, it should not matter which physical mac you end
# up using, but I take no responsibility if you change where you sit, and stuff
# suddenly doesn't work >_>.
#
# ========= Initial Setup Commands (should only be run once, probably!) ========
#
# Run these following commands:
# 1) docker-machine create --driver virtualbox sommelier
#
# If docker-machine doesn't run, you'll need to: brew install docker-machine
# Wait for 1) to finish running completely before running 2)!!
# 2) eval $(docker-machine env sommelier)
#
# `cd` into the whichever directory contains this Dockerfile then run 3)
# If docker doesn't run, you'll need to: brew install docker
# 3) docker build -t ft_sommelier .
# 4) docker volume create notebooks
#
# ================== Starting up a ft_sommelier container ======================
#
# Remember the 8888/?token=... part that will show up when you run 5)!!
# 5) docker run -it -p 8888:8888 -v notebooks:/notebooks ft_sommelier
#
# You can get your <docker-host-ip> with: docker-machine ip sommelier
# In your browser address:
# 6) <docker-host-ip>:8888/?token=...%
#
# ==================== What to do if I restart or log out? =====================
#
# If you log out or restart your computer you'll need to restart the
# docker machine when you log back into your mac. Run the following:
#
# 7) docker-machine start sommelier
# 8) eval $(docker-machine env sommelier)
# Then you can proceed to re-run steps 5) and 6) again
#
# ================= Finished the project and want to cleanup? ==================
#
# After you are done with the project it might be a good idea to clean up all
# images and the virtual machine since they take up a LOT of space...
# (Do it for Tony!!!)
#
# WARNING: THE FOLLOWING COMMANDS WILL DELETE ALL NOTEBOOKS AND DATA!!
#
# 9) docker stop $(docker ps -a -q)
# 10) docker rmi $(docker images -a -q)
# 11) docker volume prune
# 12) docker-machine rm sommelier

FROM debian

# Installing prerequisites for miniconda
RUN apt-get -y update --fix-missing && apt-get -y upgrade
RUN apt-get install -y wget bzip2 ca-certificates git build-essential \
python-dev libglib2.0-0 libxext6 libsm6 libxrender1 pandoc libav-tools ffmpeg
RUN apt-get clean && rm -rf /var/lib/apt/lists/*

# Installing miniconda
RUN echo 'export PATH=/opt/conda/bin:$PATH' > /etc/profile.d/conda.sh
RUN wget https://repo.continuum.io/miniconda/Miniconda3-4.3.27-Linux-x86_64.sh \
-O ~/miniconda.sh
RUN /bin/bash ~/miniconda.sh -b -p /opt/conda
RUN rm ~/miniconda.sh
RUN mkdir -p /notebooks
ENV PATH $PATH:/opt/conda/bin

# Installing scientific python stack
RUN conda install gcc_linux-64 cython numpy pandas matplotlib jupyter

# Container config
WORKDIR /notebooks
EXPOSE 8888
CMD ["jupyter", "notebook", "--ip=0.0.0.0", "--allow-root", "--no-browser"]
