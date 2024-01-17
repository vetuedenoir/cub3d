/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <kscordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:30:26 by kvisouth          #+#    #+#             */
/*   Updated: 2024/01/12 15:18:51 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

//for minimap
# define MINI_BLOCK 5
# define MINI_T		50
//# define MINI_SIZE MINI_BLOCK * MINI_T
# define MINI_SIZE	250
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
//# define K_W		119
# define K_S		115
# define K_A		113
//# define K_A		97
# define K_D		100
# define ECHAP		65307
//# define M			109
# define M			44

#define TICS 30000

# define PI 3.14159265358979323846264338327950288419716939937510582097494459230

//# define ROTATION_SPEED 1 * (PI / 180) 
# define ROTATION_SPEED 0.036

# define MOUV_SPEED     0.08
//# define FOV            66 * (PI / 180)
# define FOV		1.15191730631625754988078824680997058749198913574219

# define X 0
# define Y 1  

#endif