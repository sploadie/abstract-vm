/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandFactory.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 21:05:24 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/05/10 15:53:51 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERANDFACTORY_H
# define OPERANDFACTORY_H

# include "IOperand.hpp"

# ifndef OPERANDFACTORY_H_DEFINED
    #  define OPERANDFACTORY_H_DEFINED
    class OperandFactory;
    #  include "Operand.hpp"
# endif

class OperandFactory {
public:
	typedef IOperand const * (OperandFactory::*IOPFP)(std::string const &) const;
	OperandFactory( void );
	OperandFactory( OperandFactory const & obj );
	~OperandFactory( void );
	OperandFactory & operator=( OperandFactory const & rhs );

	IOperand const * createOperand( eOperandType type, std::string const & value ) const;
private:
	IOperand const * createInt8( std::string const & value ) const;
	IOperand const * createInt16( std::string const & value ) const;
	IOperand const * createInt32( std::string const & value ) const;
	IOperand const * createFloat( std::string const & value ) const;
	IOperand const * createDouble( std::string const & value ) const;
};

#endif
