/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:21:12 by vpolojie          #+#    #+#             */
/*   Updated: 2024/02/13 14:53:58 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP
#include <stack>
#include <algorithm>

class RPN
{
private:
    std::stack<int> stack;
    std::string     arg;
    char            tab[4];
public:
    RPN();
    RPN(const RPN &copy);
	RPN &operator=(RPN const &_OpCopy);
    ~RPN();

    void    set_operations(void);
    void    set_arg(char *arg);
    void    set_stack();
    void    proceed_operation(int &_tmp_result, int j);
    std::string get_arg(void) const;
};

int     parse_arg(char *arg);

#endif
