#ifndef FUNCTIONS_H
# define FUNCTIONS_H

#include "structures.h"

int		initWindow(void);
void	setup(void);
void	destroyWindow(void);
void	render(void);
void	update(void);
void	processInput(void);

void    renderPlayer(void);
void    movePlayer(float deltaTime);

#endif 