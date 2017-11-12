Resultados_hw4.pdf: c1.pdf c2.pdf c3.pdf c4.pdf c5.pdf c6.pdf c7.pdf c8.pdf t1.pdf t2.pdf t3.pdf t4.pdf
	pdflatex Resultados_hw4.tex
c1.pdf c2.pdf c3.pdf c4.pdf c5.pdf c6.pdf c7.pdf c8.pdf t1.pdf t2.pdf t3.pdf t4.pdf: a.out
	python Plots.py
a.out: cond_ini_cuerda.dat cond_ini_tambor.dat
	cc Ondas.c