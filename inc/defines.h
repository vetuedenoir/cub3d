/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <kscordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:30:26 by kvisouth          #+#    #+#             */
/*   Updated: 2023/12/05 17:00:02 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

//for minimap

# define MINI_BLOCK 20
# define MINI_T		40
# define MINI_SIZE MINI_BLOCK * MINI_T
# define MINI_PERSO 4
# define MINI_WALL_COLOR 0xFF000066
# define MINI_FLOOR_COLOR 0xFF99CCFF
# define MINI_PERSO_COLOR 0xFFFF3333

//key_presse
# define K_UP		65362
# define K_DOWN		65364
# define K_LEFT		65361
# define K_RIGHT	65363
# define K_W		122
# define K_S		115
# define K_A		113
# define K_D		100
# define ECHAP		65307

# define PI 3.14159265358979323846264338327950288419716939937510582097494459230

# define ROTATION_SPEED 2 * (PI / 180) 
# define MOUV_SPEED     0.1
# define FOV            90 * (PI / 180)

# define X 0
# define Y 1  

# define COUCOU() printf("salut les gars\n");

#endif