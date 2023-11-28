interface Movie{
    title: string;
    year: number;
}

interface MovieFilter{
    (m: Movie) : boolean;
}

class MoveDb{
    private movies: Movie[];

    constructor() {
        this.movies = [];
    }

    addMovie(movie:Movie) : Movie{
        this.movies.push(movie);
        return movie;
    }

    addMovieByTitle(title: string, year: number) : Movie{
        this.movies.push({title, year});
        return {title, year};
    }

    movieFilter(func: MovieFilter){
        console.log(this.movies.filter(func));
    }
}

const obj: Movie = {
    title: "abc",
    year: 2003
}

const printMovie = (movie: Movie) => {
    console.log(`title: ${movie.title} year: ${movie.year ?? "'"}`);
}

printMovie(obj);

const movieDb = new MoveDb();
movieDb.addMovieByTitle("Hi", 1999);
movieDb.addMovie(obj);
movieDb.movieFilter((movie) => (movie.year >= 1999));

let x:number = 4;
console.log(x);