/*
# Copyright (C) 2011 ~ 2012 Deepin, Inc.
#                         2011 ~ 2012 Xu Bin
# File Watchdog
# Author: Xu Bin <xosdeveloper@gmail.com>
# Maintainer: Xu Bin <xosdeveloper@gmail.com>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program. If not, see <http://www.gnu.org/licenses/>
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>
#include <errno.h>
#include <sys/inotify.h>

int main(int argc, char **argv)
{
	if (argc != 2) {
		printf("Usage: %s <file/dir> \n", argv[0]);
		return -1;
	}

	unsigned char buf[1024] = { 0 };
	struct inotify_event *event = NULL;

	int fd = inotify_init();
	int wd = inotify_add_watch(fd, argv[1], IN_ALL_EVENTS);

	for (;;) {
		fd_set fds;
		FD_ZERO(&fds);
		FD_SET(fd, &fds);

		if (select(fd + 1, &fds, NULL, NULL, NULL) > 0) {
			int len, index = 0;
			while (((len = read(fd, &buf, sizeof(buf))) < 0)
			       && (errno == EINTR)) ;
			while (index < len) {
				event = (struct inotify_event *)(buf + index);

				/*
				   process your data
				   event->mask)
				   event->name)
				 */
				   printf("sth changed\n");

				index +=
				    sizeof(struct inotify_event) + event->len;
			}
		}
	}

	inotify_rm_watch(fd, wd);

	return 0;
}
