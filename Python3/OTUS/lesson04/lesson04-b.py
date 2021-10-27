from flask import Flask, render_template, redirect, url_for


app = Flask(__name__)


@app.route('/')
def index_page():
    # return '<h1>Hello World!</h1>'
    # return render_template('index.html')
    names_list = ['John', 'Jimm', 'Sara']
    return render_template('index.html', names=names_list)


# @app.route('/hello')
# def hello_page():
#     return '<h2>Hello page!</h2>'


@app.route('/hello/')
@app.route('/hello/<name>/')
def hello_page(name=None):
    # if name is None:
    #     name = 'Page'
    if not name:
        name = 'Page'
    return f'<h2>Hello {name}!</h2>'


@app.route('/article/')
@app.route('/article/<int:a_id>/')
def article_page(a_id=None):
    if a_id is None:
        a_id = 1
        return redirect(url_for('article_page', a_id=1))
    return render_template('article.html', a_id=a_id)


@app.route('/article/<string:a_id>/')
def article_page_srt(a_id):
    return f'<h1>Nothing for Article {a_id}</h1>', 404


if __name__ == '__main__':
    app.run(host='localhost', port=8084)
