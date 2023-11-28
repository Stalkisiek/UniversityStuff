import {FC} from "react";

interface NumberSpanProps{
    number: number;
}

export const NumberSpan: FC<NumberSpanProps> = ({number}: NumberSpanProps) => {
    return <><span>{number}</span></>
}

