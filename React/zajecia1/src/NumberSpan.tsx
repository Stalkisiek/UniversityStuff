import {FC, FunctionComponent} from "react";

interface NumberSpanProps {
number: number;
}

export const NumberSpan: FunctionComponent<NumberSpanProps> = (props : NumberSpanProps) => {
    const number = props.number;
    return  (
        <span>{number}</span>
    );
}